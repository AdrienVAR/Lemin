/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:53:42 by advardon          #+#    #+#             */
/*   Updated: 2019/08/11 11:53:47 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*
** Initialize the values in the bfs struct
*/

void init_queue(t_anthill *anthill, t_bfs *q)
{
    q->connex = NULL;
    q->bfs_round = 0;
    q->que_len = 1;
    init_room_queue(q->que_in);
    init_room_queue(q->que_out);
    q->room_que_in = 0;
    q->room_que_out = 0;
    q->que_in[q->room_que_in] = start_id(anthill);
    q->end_room = end_id(anthill);
    q->end_bfs = 0;
}

/*
** Record a value of 1 given the room had been visited
*/

void    is_visited (t_anthill *anthill, int id_visited_room, int parent_id)
{
    t_room *actual;

	actual = anthill->l_room;
	while (actual)
	{
        if(actual->id == id_visited_room)
        {
            actual->visited = 1;
            actual->parent_id = parent_id;
            return;
        }
		actual = actual->next;
	}
}

/*
** Return 1 if room had been visited, 0 otherwise
*/

int was_visited(t_anthill *anthill, int id_room)
{
    t_room *actual;

	actual = anthill->l_room;
	while (actual)
	{
        if(actual->id == id_room)
        {
            if (actual->visited == 1)
                return(1);
            else
                return (0);
        }
		actual = actual->next;
	}
    return(0);
}

/*
** Find the starting room
*/

int start_id(t_anthill *anthill)
{
    t_room *actual;

	actual = anthill->l_room;
	while (actual)
	{
        if(actual->start == 1)
            return (actual->id);
		actual = actual->next;
	}
    return (0);
}

/*
** Find the ending room
*/

int end_id(t_anthill *anthill)
{
    t_room *actual;

	actual = anthill->l_room;
	while (actual)
	{
        if(actual->end == 1)
            return (actual->id);
		actual = actual->next;
	}
    return (0);
}
