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

int    process_neighbours(t_anthill *anthill, t_room *actual, t_queue *q, int round)
{
    t_connex    *neighbour;

    neighbour = anthill->graph->array[actual->id].next;
    while(neighbour)
    { 
        if(neighbour->in_path == 1)
        {
            if (anthill->tab_room[neighbour->room_id].visited != round && neighbour->value == - 1)
            {
            anthill->tab_room[neighbour->room_id].visited = round;
            anthill->tab_room[neighbour->room_id].parent_id = actual->id;
            neighbour->next->in_path = 0;
            enqueue(q, &anthill->tab_room[neighbour->room_id]); 
            if (neighbour->room_id == anthill->id_end) 
                return 1; 
            }
        }

        if (anthill->tab_room[neighbour->room_id].visited != round && neighbour->value != 1)
        {
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
