
# include "./libft/libft.h"

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