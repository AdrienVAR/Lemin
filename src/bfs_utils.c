
#include "../includes/lem-in.h"

/*
** Record a value of 1 given the room had been visited
*/

void    is_visited (t_graph *graph, int id_visited_room)
{
    graph->array[id_visited_room]->value = 1;
}

/*
** Return 1 if room had been visited, 0 otherwise
*/

int was_visited(t_graph *graph, int id_room)
{
    if (graph->array[id_room]->value == 1)
        return (1);
    else
        return (0);
}

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

int end_id(t_anthill *anthill)
{
    t_room *actual;

	actual = anthill->l_room;
	while (actual)
	{
        if(actual->end = 1)
            return (actual->id);
		actual = actual->next;
	}
    return (0);
}
