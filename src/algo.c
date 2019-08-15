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
		room->in_path = 1;
		parent_id = room->parent_id;
		actualize_connex(anthill, id, parent_id);
		id = parent_id;
	}
}

/*
** For each path, add the connected rooms from start to end in an
** adjacency list.
*/

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

/*
** Return the number of room from start to end in this path
*/

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

void	sort_path(t_graph *path, int nb_path)
{
	int i;
	int	j;
	t_connex	*tmp_connex;

	i = 0;
	tmp_connex = NULL;
	while (i < nb_path - 1)
	{
		j = i + 1;
		while (j < nb_path)
		{
			if (len_path(path->array[i].next) > len_path(path->array[j].next))
			{
				tmp_connex = path->array[i].next;
				path->array[i].next = path->array[j].next;
				path->array[j].next = tmp_connex;
			}
			j++;	
		}
		i++;
	}
}


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

/*
** Count how many operations are necessary to move all the ants in this graph.
*/

int calc_nb_op(t_graph *path, int nb_ant, int nb_path)
{
	int nb_op;
	int len_paths;
	int i;

	i = 0;
	len_paths = 0;
	while(i < nb_path)
	{
		len_paths += len_path(path->array[i].next);
		i++;
	}
	nb_op = (nb_ant + len_paths) / nb_path;
	return (nb_op);
}


int		nb_paths(t_graph *path)
{
	int i;

	i = 0;
	while(path->array[i].next)
	i++;
	return(i);
}

/*
** Entry point of the algo.
** Implementation of a simplified Edmonds-Karp algorithm.
*/

void    algo(t_anthill *anthill)
{
	t_graph		*path;
	t_graph		*best_path;
	anthill->nb_path = 0;
	int nb_op;

	anthill->nb_op= 10000000;
	nb_op = 0;
	while (anthill->nb_ant > anthill->nb_path  && bfs(anthill))
	{
		add_flow(anthill);
		
		anthill->nb_path++;

		reinit_graph(anthill->graph);
		path = create_graph(anthill->nb_path);
		fill_path(anthill, path, anthill->nb_path);
		if (calc_nb_op(path, anthill->nb_ant, anthill->nb_path) < anthill->nb_op)
		{
			anthill->nb_op = calc_nb_op(path, anthill->nb_ant, anthill->nb_path);
			reinit_graph(anthill->graph);
			best_path = create_graph(anthill->nb_path);
			fill_path(anthill, best_path, anthill->nb_path);
		}
		else
			break;
		ft_printf("ROUND :%d\n",anthill->nb_path);
		ft_putstr("GRAPH\n");
		print_graph(anthill->graph);
		ft_putstr("anthill\n");
		print_anthill(anthill);
		ft_putstr("PATH\n");
		print_graph2(path);
	}
	anthill->nb_path = nb_paths(best_path);
	sort_path(best_path, anthill->nb_path);
	print_graph(best_path);
	print_sol(anthill, best_path);
	//ft_putchar('\n');
	//ft_putnbr(anthill->nb_op);
}
