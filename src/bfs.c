/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:53:27 by advardon          #+#    #+#             */
/*   Updated: 2019/08/11 11:53:32 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void init_room_queue(int *queue)
{
    int room_que;

    room_que = 0;
    while (room_que < NB_ROOM)
    {
        queue[room_que] = 0;
        room_que++;
    }
}

void    update_queue(int *que_in, int *que_out)
{
    int room_que_out;
    
    room_que_out = 0;
    while(room_que_out < NB_ROOM)
    {
        que_in[room_que_out] = que_out[room_que_out];
        room_que_out++;
    }
    init_room_queue(que_out);
}

void    t_adj_list(t_anthill *anthill, t_bfs *q)
{
      if(!was_visited(anthill, q->connex->room_id))
        {
            q->que_out[q->room_que_out] = q->connex->room_id;
            is_visited(anthill, q->que_out[q->room_que_out], q->que_in[q->room_que_in]);
            ft_putnbr(q->que_out[q->room_que_out]); //
            if (q->que_out[q->room_que_out] == q->end_room)
                q->end_bfs = 1;
            q->room_que_out++;
        }
        q->connex = q->connex->next; 
}

/*
** Breadth first search traversal from room start to end.
*/
/*
int bfs(t_anthill *anthill, t_bfs *q)
{
    init_queue(anthill, q);
    q->connex = anthill->graph->array[q->que_in[q->room_que_in]].next;
    is_visited(anthill, q->que_in[q->room_que_in], q->que_in[q->room_que_in]);
    ft_putnbr(q->que_in[q->room_que_in]);//
    ft_putstr(" |end layer| "); //
    while(q->end_bfs == 0)
    {
        while(q->que_len && q->end_bfs == 0)
        {
            while(q->connex)
                t_adj_list(anthill, q);
            q->room_que_in++;
            q->connex = anthill->graph->array[q->que_in[q->room_que_in]].next;
            q->que_len--;
        }
        ft_putstr(" |end layer| ");
        update_queue(q->que_in, q->que_out);
        q->que_len = q->room_que_out;
        q->room_que_out = 0;
        q->room_que_in = 0;
        q->connex = anthill->graph->array[q->que_in[q->room_que_in]].next;
    }
    return (0);
}*/
int    process_neighbours(t_anthill *anthill, t_room *actual, t_queue *q, int round)
{
    t_connex    *neighbour;

    neighbour = anthill->graph->array[actual->id].next;
    while(neighbour)
    { 
        if (anthill->tab_room[neighbour->room_id].visited != round)
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
    anthill->tab_room[anthill->id_start].visited++;
    while(q->front != NULL)
    {
        actual = dequeue(q); 
        if(process_neighbours(anthill, actual, q, round))
            return (1);
    }
return(0);
}