/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:47:36 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/28 11:41:23 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Print each round of ants movements in the anthill.
** If the ant does not exist yet, create it and print it in its first room.
*/

void		print_round(t_anthill *anthill, t_graph *path, t_ant *tab_ant,
					int *path_nb_ant)
{
	int			i;
	static	int	round = 0;

	i = 0;
	while (i < anthill->nb_in)
	{
		if (tab_ant[i].is_in)
			move_ant(anthill, &tab_ant[i], tab_ant, i);
		i++;
	}
	i = 0;
	while (i < anthill->nb_path)
	{
		if (anthill->nb_in < anthill->nb_ant)
		{
			if (round >= path_nb_ant[i])
				anthill->nb_path--;
			else
				create_ant(anthill, tab_ant, path, i);
		}
		i++;
	}
	round++;
}

/*
** While all ants are not in the end room, print a new round of ants movements.
*/

void		print_sol(t_anthill *anthill, t_graph *path)
{
	t_ant	tab_ant[anthill->nb_ant];
	int		path_len[anthill->nb_path];
	int		path_nb_ant[anthill->nb_path];
	int		i;

	i = -1;
	while (++i < anthill->nb_path)
	{
		path_len[i] = len_path(path->array[i].next);
		path_nb_ant[i] = anthill->nb_op - (path_len[i] - 1);
	}
	while (anthill->nb_end != anthill->nb_ant)
	{
		print_round(anthill, path, tab_ant, path_nb_ant);
		ft_putchar('\n');
	}
}

void		print_graph(t_anthill *anthill, t_graph *graph)
{
	int			i;
	t_connex	*connex;

	i = 0;
	while (i < graph->nb_room)
	{
		ft_putstr("Path");
		ft_putnbr(i);
		ft_putstr(" : (");
		ft_putstr(anthill->tab_room[anthill->id_start].name);
		connex = graph->array[i].next;
		while (connex)
		{
			ft_putstr(")  -->   (");
			ft_putstr(anthill->tab_room[connex->room_id].name);
			connex = connex->next;
		}
		ft_putstr(")\n");
		i++;
	}
}

void		print_graph2(t_anthill *anthill, t_graph *graph)
{
	int			i;
	t_connex	*connex;

	i = 0;
	while (i < graph->nb_room)
	{
		ft_putstr("(room : ");
		ft_putstr(anthill->tab_room[i].name);
		connex = graph->array[i].next;
		while (connex)
		{
			ft_putstr(")  -->   (");
			ft_putstr(anthill->tab_room[connex->room_id].name);
			connex = connex->next;
		}
		ft_putstr(")\n");
		i++;
	}
}
