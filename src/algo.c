/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:51:34 by advardon          #+#    #+#             */
/*   Updated: 2019/08/13 11:52:51 by avanhers         ###   ########.fr       */
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
			if (neighbour->value == 1)
			{
				add_edge_side(path, i ,neighbour->room_id);
				neighbour->value = -2;
				neighbour = anthill->graph->array[neighbour->room_id].next;
			}
			else
				neighbour = neighbour->next;
		}
		i++;
	}
}

/*
int lenpath(t_anthill *anthill)
{



}
*/

/*
int	nb_rounds_sol(t_anthill *anthill)
{
	int rounds;

c



	return (rounds);
}*/


/*
** Entry point of the algo.
** Implementation of a simplified Edmonds-Karp algorithm.
*/

void    algo(t_anthill *anthill)
{
	t_graph		*path;
	anthill->nb_path = 0;

	while (anthill->nb_ant > anthill->nb_path  && bfs(anthill))
	{
	//	nb_rounds_sol();
		print_anthill(anthill);
		add_flow(anthill);
		anthill->nb_path++;
		print_graph(anthill->graph);
		ft_putchar('\n');
	}
	path = create_graph(anthill->nb_path);
	fill_path(anthill, path, anthill->nb_path);
	print_sol(anthill,path);
}
