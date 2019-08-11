

#include "../includes/lem-in.h"

t_qnode *new_node(int id)
{
    t_qnode *new;

    if (!new = (t_qnode *)malloc(sizeof(t_qnode)))
        return (0);

    new->id_room = id;
    new->next = NULL;
    return (new);
}