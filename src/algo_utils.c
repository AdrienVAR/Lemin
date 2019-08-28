/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:11:03 by advardon          #+#    #+#             */
/*   Updated: 2019/08/28 12:00:49 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Access to a room from the connections adjacency list
*/

t_room	*get_room(t_anthill *anthill, int id)
{
	t_room *room;

	room = &anthill->tab_room[id];
	return (room);
}

/*
** Return the number of rooms from start to end in this path
*/

int		len_path(t_connex *connex)
{
	t_connex	*actual;
	int			len;

	actual = connex;
	len = 0;
	while (actual)
	{
		actual = actual->next;
		len++;
	}
	return (len);
}

/*
** Return the number of paths found in the anthill.
*/

int		nb_paths(t_graph *path)
{
	int i;

	i = 0;
	while (path->array[i].next)
		i++;
	return (i);
}

/*
** Sort paths from shorter nb of room to longest.
*/

void	sort_path(t_graph *path, int nb_path)
{
	int			i;
	int			j;
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

/*
** Return how many operations are necessary to move all the ants in this graph.
** The formulaused is (nb of ant + lenght of all valid paths) / nb of paths.
*/

int		calc_nb_op(t_graph *path, int nb_ant, int nb_path)
{
	int nb_op;
	int len_paths;
	int i;

	i = 0;
	len_paths = 0;
	while (i < nb_path)
	{
		len_paths += len_path(path->array[i].next);
		i++;
	}
	nb_op = (nb_ant + len_paths) / nb_path;
	return (nb_op);
}
