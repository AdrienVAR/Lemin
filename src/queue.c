

#include "../includes/lem-in.h"

/*
t_qnode *new_node(int id)
{
    t_qnode *new;

    if (!new = (t_qnode *)malloc(sizeof(t_qnode)))
        return (0);

    new->id_room = id;
    new->next = NULL;
    return (new);
}*/

t_queue* createqueue(t_anthill *anthill)
{
    t_queue* q ;

    (void)anthill;
    if(!(q = (t_queue*)malloc(sizeof(t_queue))))
        error_message();
    garbage_collector(&(anthill->head_gar_c), q);
    q->front = q->rear = NULL;
    return q;
}

void enqueue(t_queue *q, t_room *room)
{
    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) 
    {
        q->front = room;
        q->rear = room;
        q->front->next = NULL;
        return;
    }
    // Add the new node at the end of queue and change rear
    q->rear->next = room;
    q->rear = room;
    q->rear->next= NULL;
}

t_room* dequeue(t_queue *q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return NULL;
    // Store previous front and move front one node ahead
    t_room* temp = q->front;
    q->front = q->front->next;
    temp->next = NULL;
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}

void print_queue(t_queue *q)
{
    t_room *actual;
    actual = q->front;

    while (actual)
    {
        ft_putnbr(actual->id);
        ft_putstr("--->");
        actual = actual->next;
    }
}