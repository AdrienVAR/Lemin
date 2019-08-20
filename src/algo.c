/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:51:34 by advardon          #+#    #+#             */
/*   Updated: 2019/08/19 17:53:00 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Search the parent_id of a room in its connection adjacency list and reduce
** this connection's flow value by 1.
** Search the id from which the room is parent in its connection adjacency list
** and increase this connection's flow value by 1.
*/

void	actualize_connex(t_anthill *anthill, int id, int parent_id)
{
	t_connex *actual;

	actual = anthill->graph->array[id].next;
	while (actual)
	{
		if (actual->room_id == parent_id)
		{
			actual->value--;
			break ;
		}
		actual = actual->next;
	}
	actual = anthill->graph->array[parent_id].next;
	while (actual)
	{
		if (actual->room_id == id)
		{
			actual->value++;
			break ;
		}
		actual = actual->next;
	}
}

/*
** From end room to start room, through the parent_id allocated by bfs
** add a flow of +1 from parent_id to id and a flow of -1 in the opposite
** direction.
*/

void	add_flow(t_anthill *anthill)
{
	t_room	*room;
	int		id;
	int		parent_id;

	room = &anthill->tab_room[anthill->id_end];
	id = room->id;
	while (id != anthill->id_start)
	{
		room = &anthill->tab_room[id];
		parent_id = room->parent_id;
		actualize_connex(anthill, id, parent_id);
		id = parent_id;
	}
}

/*
** For each path, add the connected rooms from start to end in an
** adjacency list.
*/

void	fill_path(t_anthill *anthill, t_graph *path, int nb_path)
{
	int			i;
	t_connex	*neighbour;
	t_room		*room;

	i = 0;
	while (i < nb_path)
	{
		neighbour = anthill->graph->array[anthill->id_start].next;
		while (neighbour)
		{
			if (neighbour->value == 1 && neighbour->in_path == 0)
			{
				room = get_room(anthill, neighbour->room_id);
				room->in_path = 1;
				add_edge_side(anthill, path, i, neighbour->room_id);
				neighbour->in_path = 1;
				neighbour = anthill->graph->array[neighbour->room_id].next;
			}
			else
				neighbour = neighbour->next;
		}
		i++;
	}
}

/*
** Return how many operations are necessary to move all the ants in this graph.
** The formulaused is (nb of ant + lenght of all valid paths) / nb of paths.
*/

int		calc_nb_op(t_graph *path, int nb_ant, int nb_path)
{
	int nb_op;
	int len_paths;
	int i;

	i = 0;
	len_paths = 0;
	while (i < nb_path)
	{
		len_paths += len_path(path->array[i].next);
		i++;
	}
	nb_op = (nb_ant + len_paths) / nb_path;
	return (nb_op);
}

/*
** Entry point of the algo.
** Implementation of a simplified Edmonds-Karp algorithm.
*/

void	algo(t_anthill *anthill)
{
	t_graph		*path;
	t_graph		*best_path;

	while (anthill->nb_ant > anthill->nb_path && bfs(anthill))
	{
		add_flow(anthill);
		anthill->nb_path++;
		reinit_graph(anthill->graph);
		path = create_graph(anthill, anthill->nb_path);
		fill_path(anthill, path, anthill->nb_path);
		if (calc_nb_op(path, anthill->nb_ant, anthill->nb_path) <
		anthill->nb_op)
		{
			anthill->nb_op = calc_nb_op(path, anthill->nb_ant,
			anthill->nb_path);
			reinit_graph(anthill->graph);
			best_path = create_graph(anthill, anthill->nb_path);
			fill_path(anthill, best_path, anthill->nb_path);
		}
		else
			break ;
	}
	anthill->nb_path = nb_paths(best_path);
	sort_path(best_path, anthill->nb_path);
	print_sol(anthill, best_path);
}
