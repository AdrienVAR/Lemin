/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:53:27 by advardon          #+#    #+#             */
/*   Updated: 2019/08/19 17:53:25 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Ascending from Descending
** When we come from a room whch is not in a valid path AND we enter a room that
** IS in a valid path, the ONLY neighbor we can visit is the neigbhor with a
** connexion of -1.
** Until the end of this bfs, this neigboring room is not consider in a valid
** path anymore (hence we set the in_path bool of this neigbhor to 0).
** Return 1 if we can queue the neighbor connected by a flow of -1
*/

int	asc_f_dsc(t_anthill *anthill, t_connex *neigh, t_room *actual, t_queue *q)
{
	t_room *check_room;

	check_room = &anthill->tab_room[neigh->room_id];
	if (check_room->visited != anthill->round && neigh->value == -1)
	{
		check_room->visited = anthill->round;
		check_room->in_path = 0;
		check_room->parent_id = actual->id;
		enqueue(q, &anthill->tab_room[neigh->room_id]);
		return (1);
	}
	return (0);
}

/*
** Enqueue this neighbor if he has a connection of 0 or -1.
** Return 1 if we reach the end room, 0 if not.
*/

int	check_neigh(t_anthill *anthill, t_connex *neigh, t_room *actual, t_queue *q)
{
	t_room *check_room;

	check_room = &anthill->tab_room[neigh->room_id];
	if (check_room->visited != anthill->round && neigh->value != 1)
	{
		check_room->visited = anthill->round;
		check_room->parent_id = actual->id;
		enqueue(q, &anthill->tab_room[neigh->room_id]);
		if (neigh->room_id == anthill->id_end)
			return (1);
	}
	return (0);
}

int	find_connex(t_anthill *anthill, t_room *actual)
{
	t_connex	*neighbour;

	neighbour = anthill->graph->array[actual->id].next;
	while (neighbour)
	{
		if (neighbour->room_id == actual->parent_id)
		{
			if (neighbour->value == 1)
				return (-neighbour->value);
			else
				return (1);
		}
		neighbour = neighbour->next;
	}
	return (1);
}

/*
** Process through all neighbour of actual and add a valid neighbour to queue
** To test if we had to add neighbour to the queue we used:
** Dir == 1 if we come from a room that is not yet in a valid path
** (connex between rooms == 0). Dir == -1 if we come from a room that
** is already in a valid path (connex between rooms == -1).
** First we test the case where
** Return 1 if the BFS reach the end room, 0 if not.
*/

int	process_neighbours(t_anthill *anthill, t_room *actual, t_queue *q)
{
	t_connex	*neighbour;
	int			dir;

	neighbour = anthill->graph->array[actual->id].next;
	dir = find_connex(anthill, actual);
	while (neighbour)
	{
		if (actual->in_path && dir == 1)
		{
			if (asc_f_dsc(anthill, neighbour, actual, q))
				if (neighbour->room_id == anthill->id_end)
					return (1);
		}
		else if (check_neigh(anthill, neighbour, actual, q))
			return (1);
		neighbour = neighbour->next;
	}
	return (0);
}

/*
** Use of breadth first search algorithm for searching the shortest path
** between room start and room end.
*/

int	bfs(t_anthill *anthill)
{
	t_queue		*q;
	t_room		*actual;

	anthill->round++;
	q = createqueue(anthill);
	enqueue(q, &anthill->tab_room[anthill->id_start]);
	anthill->tab_room[anthill->id_start].visited = anthill->round;
	while (q->front != NULL)
	{
		actual = dequeue(q);
		if (process_neighbours(anthill, actual, q))
			return (1);
	}
	return (0);
}
