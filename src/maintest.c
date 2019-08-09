/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:41:23 by advardon          #+#    #+#             */
/*   Updated: 2019/07/31 14:41:25 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*
typedef struct s_connexion
{
	int room_id;
	struct s_connexion *next_con;
}	t_connex;
*/

/*
** Record a value of 1 given the room had been visited
*/

void    is_visited (t_graph *graph, int id_visited_room)
{
    graph->room[id_visited_room]->value = 1;
}

/*
** Return 1 if room had been visited, 0 otherwise
*/

int was_visited(t_graph *graph, int id_room)
{
    if (graph->room[id_room]->value == 1)
        return (1);
    else
        return (0);
}


void init_queue(int *queue)
{
    int room_que_out;

    room_que_out = 0;

    while (room_que_out < NB_ROOM)
    {
        queue[room_que_out] = 0;
        room_que_out++;
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
    init_queue(que_out);
}

int bfs(t_graph *graph, t_room *start, t_room *end)
{
    int que_in[NB_ROOM];
    int que_out[NB_ROOM];
    int room_que_out;
    int room_que_in;
    int end_room;
    int end_bfs;

    end_room = end->room_id;
    init_queue(que_in);
    init_queue(que_out);
    room_que_in = 1;
    room_que_out = 1;
    que_in[room_que_in] = start->room_id;
    is_visited(graph, start->room_id);
    end_bfs = 0;
    ft_putnbr(que_in[1]);//
    while(end_bfs == 0)
    {
        while(que_in[room_que_in] && end_bfs == 0)
        {
            while(graph->room[que_in[room_que_in]]->next_con)
            {
                if(!was_visited(graph, graph->room[que_in[room_que_in]]->next_con->room_id))
                {
                    que_out[room_que_out] = graph->room[que_in[room_que_in]]->next_con->room_id;
                    is_visited(graph, que_out[room_que_out]);
                }
                else
                    room_que_out--;              
                graph->room[que_in[room_que_in]]->next_con = graph->room[que_in[room_que_in]]->next_con->next_con;
                if (que_out[room_que_out] == end_room)
                {
                    ft_putnbr(que_out[room_que_out]); //
                    end_bfs = 1;
                    break;
                }
                ft_putnbr(que_out[room_que_out]); //
                room_que_out++;
            }
            room_que_in++;
        }
        update_queue(que_in, que_out);
        room_que_out = 1;
        room_que_in = 1;
    }

    return (0);
}

#include <stdio.h>

int main (void)
{
    t_graph graph;
    t_room  room1;
    t_room  room2;
    t_room  room3;
    t_room  room4;
    t_room  room5;
    t_room  room6;
    t_room  room7;
    t_room  room8;
    t_room  *start;
    t_room  *end;

    t_connex con_1_2;
    t_connex con_1_3;
    t_connex con_2_5;
    t_connex con_2_1;
    t_connex con_3_4;
    t_connex con_3_6;
    t_connex con_4_7;
    t_connex con_5_6;
    t_connex con_6_8;
    t_connex con_7_8;

    graph.room[1] = &room1;
    graph.room[2] = &room2;
    graph.room[3] = &room3;
    graph.room[4] = &room4;
    graph.room[5] = &room5;
    graph.room[6] = &room6;
    graph.room[7] = &room7;
    graph.room[8] = &room8;

    room1.room_id = 1;
    room2.room_id = 2;
    room3.room_id = 3;
    room4.room_id = 4;
    room5.room_id = 5;
    room6.room_id = 6;
    room7.room_id = 7;
    room8.room_id = 8;

    room1.value = 0;
    room2.value = 0;
    room3.value = 0;
    room4.value = 0;
    room5.value = 0;
    room6.value = 0;
    room7.value = 0;
    room8.value = 0;

    room1.next_con = &con_1_2;
    room1.next_con->next_con = &con_1_3;
    room2.next_con = &con_2_5;
    room2.next_con->next_con = &con_2_1;
    room3.next_con = &con_3_4;
    room3.next_con->next_con = &con_3_6;
    room4.next_con = &con_4_7;
    room5.next_con = &con_5_6;
    room6.next_con = &con_6_8;
    room7.next_con = &con_7_8;

    room1.next_con->room_id = 2;
    room1.next_con->next_con->room_id = 3;
    room2.next_con->room_id = 5;
    room2.next_con->next_con->room_id = 1;
    room3.next_con->room_id = 4;
    room3.next_con->next_con->room_id = 6;
    room4.next_con->room_id = 7;
    room5.next_con->room_id = 6;
    room6.next_con->room_id = 8;
    room7.next_con->room_id = 8;
    room8.next_con = NULL;

    start = &room1;
    end = &room8;

    bfs(&graph, start, end);

    return (0);
}