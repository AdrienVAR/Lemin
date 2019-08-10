
#include "../includes/lem-in.h"

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
