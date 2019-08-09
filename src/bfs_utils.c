
#include "../includes/lem-in.h"

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