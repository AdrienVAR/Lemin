/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:14:56 by advardon          #+#    #+#             */
/*   Updated: 2019/08/19 17:53:44 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	Create a queue. Front and Rear initialized at NULL.
*/

t_queue		*createqueue(t_anthill *anthill)
{
	t_queue *q;

	(void)anthill;
	if (!(q = (t_queue*)malloc(sizeof(t_queue))))
		error_message(anthill, "MALLOC ERROR\n");
	garbage_collector(&(anthill->head_gar_c), q);
	q->front = NULL;
	q->rear = NULL;
	return (q);
}

/*
**	If queue is empty, then new node is both front and rear.
**  Else, add the new node at the end of queue and change rear.
*/

void		enqueue(t_queue *q, t_room *room)
{
	if (q->rear == NULL)
	{
		q->front = room;
		q->rear = room;
		q->front->next = NULL;
		return ;
	}
	q->rear->next = room;
	q->rear = room;
	q->rear->next = NULL;
}

/*
**  If queue is empty, return NULL.
**	Store front current address in tmp and move front one node ahead.
**  If front becomes NULL, then change rear also to NULL
*/

t_room		*dequeue(t_queue *q)
{
	t_room *temp;

	if (q->front == NULL)
		return (NULL);
	temp = q->front;
	q->front = q->front->next;
	temp->next = NULL;
	if (q->front == NULL)
		q->rear = NULL;
	return (temp);
}
