
#include "../includes/lem-in.h"

void init_queue(t_anthill *anthill, t_queue *q)
{
    init_room_queue(q->que_in);
    init_room_queue(q->que_out);
    q->room_que_in = 0;
    q->room_que_out = 0;
    q->que_in[q->room_que_in] = start_id(anthill);
    q->end_room = end_id(anthill);
    q->end_bfs = 0;
}

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

int bfs(t_anthill *anthill, t_queue *q)
{
    init_queue(anthill, q);
    q->que_len = 1;
    is_visited(anthill, q->que_in[q->room_que_in], q->que_in[q->room_que_in]);
    ft_putnbr(q->que_in[q->room_que_in]);//
    ft_putstr(" |end layer| "); //
    while(q->end_bfs == 0)
    {
        while(q->que_len && q->end_bfs == 0)
        {
            while(anthill->graph->array[q->que_in[q->room_que_in]].next)
            {
                if(!was_visited(anthill, anthill->graph->array[q->que_in[q->room_que_in]].next->room_id))
                {
                    q->que_out[q->room_que_out] = anthill->graph->array[q->que_in[q->room_que_in]].next->room_id;
                    is_visited(anthill, q->que_out[q->room_que_out], q->que_in[q->room_que_in]);
                    ft_putnbr(q->que_out[q->room_que_out]); //
                    if (q->que_out[q->room_que_out] == q->end_room)
                        q->end_bfs = 1;
                    q->room_que_out++;
                }
                anthill->graph->array[q->que_in[q->room_que_in]].next = anthill->graph->array[q->que_in[q->room_que_in]].next->next;
            }
            q->que_len--;
            q->room_que_in++;
        }
        ft_putstr(" |end layer| ");
        update_queue(q->que_in, q->que_out);
        q->que_len = q->room_que_out;
        q->room_que_out = 0;
        q->room_que_in = 0;
    }
    return (0);
}