/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:51:34 by advardon          #+#    #+#             */
/*   Updated: 2019/08/13 14:50:07 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void  actualize_connex(t_anthill *anthill, int id, int parent_id)
{
	t_connex *actual;

	actual = anthill->graph->array[id].next;

	while(actual)
	{
		if (actual->room_id == parent_id)
		{
			actual->value--;
			break;
		}
		actual = actual->next;
	} 
	actual = anthill->graph->array[parent_id].next;
	while(actual)
	{
		if (actual->room_id == id)
		{
			actual->value++;
			break;
		}
		actual = actual->next;
	}
}

void    add_flow(t_anthill *anthill)
{
	t_room *room;
	int     id;
	int     parent_id;

	room = &anthill->tab_room[anthill->id_end];
	id = room->id;
	while (id != anthill->id_start)
	{
		room = &anthill->tab_room[id];
		parent_id = room->parent_id;
		actualize_connex(anthill, id, parent_id);
		id = parent_id;
	}
}

void	fill_path(t_anthill *anthill,t_graph *path,int nb_path)
{
	int i;
	t_connex *neighbour;

	i = 0;
	while (i < nb_path)
	{
		neighbour = anthill->graph->array[anthill->id_start].next;
		while (neighbour)
		{
			if (neighbour->value == 1 && neighbour->in_path == 0)
			{
				add_edge_side(path, i ,neighbour->room_id);
				neighbour->in_path = 1;
				neighbour = anthill->graph->array[neighbour->room_id].next;
			}
			else
				neighbour = neighbour->next;
		}
		i++;
	}
}

int len_path(t_connex *connex)
{
    t_connex *actual;
    int len;

    actual = connex;
    len = 0;
    while(actual)
    {
        actual = actual->next;
        len++;
    }
    return (len);
}

/*
** Entry point of the algo.
** Implementation of a simplified Edmonds-Karp algorithm.
*/

void	reinit_graph(t_graph *graph)
{
	int i;
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

void    algo(t_anthill *anthill)
{
	t_graph		*path;
	anthill->nb_path = 0;

	while (anthill->nb_ant > anthill->nb_path  && bfs(anthill))
	{
	//	nb_rounds_sol();
		add_flow(anthill);
		anthill->nb_path++;

		reinit_graph(anthill->graph);
		path = create_graph(anthill->nb_path);
		fill_path(anthill, path, anthill->nb_path);
		print_graph(path);
		ft_putchar('\n');
	}
	path = create_graph(anthill->nb_path);
	fill_path(anthill, path, anthill->nb_path);
	print_graph(path);
	ft_putnbr(len_path(path->array[0].next));
	print_sol(anthill,path);
}
