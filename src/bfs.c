/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:53:27 by advardon          #+#    #+#             */
/*   Updated: 2019/08/12 14:44:17 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"


int find_connex(t_anthill *anthill, t_room *actual)
{
    t_connex    *neighbour;

    neighbour = anthill->graph->array[actual->id].next;

    while(neighbour)
    {
        if(neighbour->room_id == actual->parent_id)
        {
            if(neighbour->value == 1)
                return(-neighbour->value);
            else
                return (1);
            
        }
        neighbour = neighbour->next;
    }
    return (1);
}


int    process_neighbours(t_anthill *anthill, t_room *actual, t_queue *q, int round)
{
	t_connex    *neighbour;
	static int	dir = 0;
	neighbour = anthill->graph->array[actual->id].next;
    dir = find_connex(anthill, actual);
	while (neighbour)
	{
        if(actual->id == 1945)
        ft_printf("id : %d id_neigh: %d ,neigh.value :%d dir : %d, in_path :%d\n", actual->id, neighbour->room_id,neighbour->value,dir, actual->in_path);
		if (actual->in_path  && dir == 1)
		{
			if (anthill->tab_room[neighbour->room_id].visited != round && neighbour->value == -1)
			{
				//dir = -1;
				anthill->tab_room[neighbour->room_id].visited = round;
				anthill->tab_room[neighbour->room_id].in_path  = 0;
				anthill->tab_room[neighbour->room_id].parent_id = actual->id;
				enqueue(q, &anthill->tab_room[neighbour->room_id]);
				if (neighbour->room_id == anthill->id_end)
					return 1;
			}
		}
		else if (actual->in_path  && dir == -1)
		{
			if (anthill->tab_room[neighbour->room_id].visited != round && neighbour->value == -1)
			{
				//dir = -1;
				anthill->tab_room[neighbour->room_id].visited = round;
				anthill->tab_room[neighbour->room_id].parent_id = actual->id;
				enqueue(q, &anthill->tab_room[neighbour->room_id]);
				if (neighbour->room_id == anthill->id_end)
					return 1;
			}
			else if (anthill->tab_room[neighbour->room_id].visited != round && neighbour->value == 0)
			{
				//dir = 1;
				anthill->tab_room[neighbour->room_id].visited = round;
				anthill->tab_room[neighbour->room_id].parent_id = actual->id;
				enqueue(q, &anthill->tab_room[neighbour->room_id]);
				if (neighbour->room_id == anthill->id_end)
					return 1;
			}
		}
		else  if (anthill->tab_room[neighbour->room_id].visited != round && neighbour->value != 1)
		{
                //dir = 1;
			anthill->tab_room[neighbour->room_id].visited = round;
			anthill->tab_room[neighbour->room_id].parent_id = actual->id;
			enqueue(q, &anthill->tab_room[neighbour->room_id]);
			if (neighbour->room_id == anthill->id_end)
				return 1;
		}
		neighbour = neighbour->next;
	}
	return (0);
}

int bfs(t_anthill *anthill)
{
    t_queue     *q;
    t_room      *actual;
    
    static int     round = 0;

    round++;
    q = createqueue();
    enqueue(q, &anthill->tab_room[anthill->id_start]);
    anthill->tab_room[anthill->id_start].visited=round;
    while (q->front != NULL)
    {
        actual = dequeue(q);
        if(process_neighbours(anthill, actual, q, round))
            return (1);
    }
	return (0);
}
