/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:51:34 by advardon          #+#    #+#             */
/*   Updated: 2019/08/12 17:21:57 by avanhers         ###   ########.fr       */
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


	//remonte end to start et ajoute 1/-1 dans connex->value

}

/*
 ** Entry point of the algo.
 ** Implementation of a simplified Edmonds-Karp algorithm.
 */
void	fill_path(t_anthill *anthill,t_graph *path,int nb_chemin)
{
	int i;
	t_connex *neighbour;

	i = 0;
	while (i < nb_chemin)
	{
		neighbour = anthill->graph->array[anthill->id_start].next;
		while (neighbour)
		{
			/*if (neighbour->value == 1 && neighbour->room_id == anthill->id_end)
			  break;*/
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


void	move_ant(t_anthill *anthill, t_ant *ant)
{
	ant->connex = ant->connex->next;
	if (ant->connex->room_id == anthill->id_end)
	{
		ant->is_in = 0;
		anthill->nb_end++;
	}
}

void 	print_round(t_anthill *anthill, t_graph *path,t_ant *tab_ant)
{
	int	i;

	i = 0;
	while (i < anthill->nb_in)
	{
		if (tab_ant[i].is_in)
		{
			move_ant(anthill, &tab_ant[i]);
			print_ant(anthill,tab_ant, i + 1 );
		}
		i++;
	}
	i = 0;
	while (i < anthill->nb_path)
	{
		if (anthill->nb_in < anthill->nb_ant)
		{
			create_ant(anthill, tab_ant, path);
			print_ant(anthill,tab_ant, anthill->nb_in);
		}
		i++;
	}
}

void	print_sol(t_anthill *anthill, t_graph *path)
{
	t_ant	tab_ant[anthill->nb_ant];
	
	while (anthill->nb_end != anthill->nb_ant)
	{
		print_round(anthill, path, tab_ant);	
		ft_putchar('\n');
	}


}

void    algo(t_anthill *anthill)
{
	t_graph		*path;
	
	anthill->nb_path = 0;

	while (anthill->nb_ant > anthill->nb_path  && bfs(anthill))
	{
		//print_anthill(anthill);
		add_flow(anthill);
		//print_graph(anthill->graph);
		anthill->nb_path++;
	}
	path = create_graph(anthill->nb_path);
	fill_path(anthill, path, anthill->nb_path);
	//print_graph(path);
	print_sol(anthill,path);
}
