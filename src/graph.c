/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:20 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/09 13:54:36 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"


t_connex	*new_connex(int dst)
{
	t_connex	*connex;

	if (!(connex = (t_connex*)malloc(sizeof(t_connex))))
		return (NULL);
	connex->room_id = dst;
	connex->next = NULL;
	return (connex);
}

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

void		print_graph(t_graph *graph)
{
	int i;
	t_connex	*connex;

	i = 1;
	while (i < graph->nb_room)
	{
		ft_putnbr(i);
		ft_putstr("->");
		connex = graph->array[i].next;
		while (connex)
		{
			ft_putnbr(connex->room_id);
			ft_putstr("-->");
			connex = connex->next;
		}
		ft_putstr("NULL\n");
		i++;
	}
}
