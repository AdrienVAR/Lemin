/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:20 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/28 11:35:16 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Create a connection from src to a room.
** Each connection is assigned the id of the connected room, a flow value,
** a bool to check if this connection is a path in the algo, and a pointer
** in case another room connected to this id is added.
*/

t_connex	*new_connex(t_anthill *anthill, int dst)
{
	t_connex	*connex;

	if (!(connex = (t_connex*)malloc(sizeof(t_connex))))
		error_message(anthill, "MALLOC ERROR\n");
	garbage_collector(&(anthill->head_gar_c), connex);
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

t_graph		*create_graph(t_anthill *anthill, int nb_room)
{
	t_graph	*graph;
	int		i;

	if (!(graph = (t_graph*)malloc(sizeof(t_graph))))
		error_message(anthill, "MALLOC ERROR\n");
	garbage_collector(&(anthill->head_gar_c), graph);
	graph->nb_room = nb_room;
	if (!(graph->array = (t_connex*)malloc(sizeof(t_connex) * (nb_room + 1))))
		error_message(anthill, "MALLOC ERROR\n");
	garbage_collector(&(anthill->head_gar_c), graph->array);
	i = 0;
	while (i <= nb_room)
	{
		graph->array[i].next = NULL;
		i++;
	}
	return (graph);
}

/*
** Reset to 0 the bool checking if a connection between two room is chosen
** for a valid path.
*/

void		reinit_graph(t_graph *graph)
{
	int			i;
	t_connex	*connex;

	i = 0;
	while (i < graph->nb_room)
	{
		connex = graph->array[i].next;
		while (connex)
		{
			connex->in_path = 0;
			connex = connex->next;
		}
		i++;
	}
}

/*
** Add edges in the adjacency of two room_ids, in both directions.
*/

int			add_edge(t_anthill *anthill, t_graph *graph, t_edge *edge)
{
	t_connex	*n_connex;

	n_connex = new_connex(anthill, edge->dst);
	n_connex->next = graph->array[edge->src].next;
	graph->array[edge->src].next = n_connex;
	n_connex = new_connex(anthill, edge->src);
	n_connex->next = graph->array[edge->dst].next;
	graph->array[edge->dst].next = n_connex;
	return (1);
}

/*
** Add edges in the adjacency of one room_id, in one direction.
*/

int			add_edge_side(t_anthill *anthill, t_graph *graph, int src, int dst)
{
	t_connex	*n_connex;
	t_connex	*actual;

	n_connex = new_connex(anthill, dst);
	actual = graph->array[src].next;
	if (!actual)
	{
		graph->array[src].next = n_connex;
		return (1);
	}
	while (actual && actual->next)
		actual = actual->next;
	actual->next = n_connex;
	return (1);
}
