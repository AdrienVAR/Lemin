/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:20 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/13 14:42:56 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"
#include <stdio.h>

t_connex	*new_connex(int dst)
{
	t_connex	*connex;

	if (!(connex = (t_connex*)malloc(sizeof(t_connex))))
		return (NULL);
	connex->room_id = dst;
	connex->value = 0;
	connex->in_path = 0;
	connex->next = NULL;
	return (connex);
}

/*
** Create a graph storing each room_id in an array.
** Each room_id has an adjacency list containing all its edges.
*/

t_graph		*create_graph(int nb_room)
{
	t_graph	*graph;
	int		i;

	if (!(graph = (t_graph*)malloc(sizeof(t_graph))))
		return (NULL);
	graph->nb_room = nb_room;
	if (!(graph->array = (t_connex*)malloc(sizeof(t_connex) * nb_room)))
		return (NULL);
	i = 0;
	while (i < nb_room)
	{
		graph->array[i].next = NULL;
		i++;
	}
	return (graph);
}

/*
** Add edges in the adjacency of two room_ids, in both directions.
*/

int			add_edge(t_graph *graph, t_edge *edge)
{
	t_connex	*n_connex;

	n_connex = new_connex(edge->dst);
	n_connex->next = graph->array[edge->src].next;
	graph->array[edge->src].next = n_connex;

	n_connex = new_connex(edge->src);
	n_connex->next = graph->array[edge->dst].next;
	graph->array[edge->dst].next = n_connex;
	return (1);
}

/*
** Add edges in the adjacency of one room_id, in one direction.
*/

int			add_edge_side(t_graph *graph, int src, int dst)
{
	t_connex	*n_connex;
	t_connex 	*actual;

	n_connex = new_connex(dst);
	actual = graph->array[src].next;
	if (!actual)
	{
		graph->array[src].next = n_connex;
		return 1;
	}
	while (actual && actual->next)
		actual = actual->next;
	actual->next = n_connex;
	return (1);
}



void		print_graph(t_graph *graph)
{
	int i;
	t_connex	*connex;

	i = 0;
	while (i < graph->nb_room)
	{
		ft_putnbr(i);
		ft_putstr("->(");
		connex = graph->array[i].next;
		while (connex)
		{

			ft_putnbr(connex->room_id);
			ft_putstr(" : ");
			ft_putnbr(connex->value);
			ft_putstr(")  -->   (");
			connex = connex->next;
		}
		ft_putstr("NULL\n");
		i++;
	}
}
