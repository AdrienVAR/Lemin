/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:24:09 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/19 14:57:12 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*
** Create an ant, assign her ID and her path. Is_in = 1 put her in the anthill.
*/

void	create_ant(t_anthill *anthill, t_ant *tab_ant, t_graph *path,
					int num_path)
{
	int i;

	anthill->nb_in++;
	i = anthill->nb_in;
	tab_ant[i - 1].id_ant = i;
	tab_ant[i - 1].path = num_path;
	tab_ant[i - 1].connex = path->array[num_path].next;
	tab_ant[i - 1].is_in = 1;
	if (tab_ant[i - 1].connex->room_id == anthill->id_end)
	{
		tab_ant[i - 1].is_in = 0;
		anthill->nb_end++;
	}
	print_ant(anthill, tab_ant, anthill->nb_in);
}

void	print_all_ant(t_anthill *anthill, t_ant *tab_ant)
{
	int i;

	i = 0;
	while (i < anthill->nb_in)
	{
		ft_putnbr(tab_ant[i].id_ant);
		ft_putstr(": path :");
		ft_putnbr(tab_ant[i].path);
		ft_putnbr(tab_ant[i].connex->room_id);
		ft_putchar('\n');
		i++;
	}
}

/*
** Move an ant to the next room, and out of the anthill if reach the end.
*/

void	move_ant(t_anthill *anthill, t_ant *ant, t_ant *tab_ant, int i)
{
	if (ant->connex->next)
		ant->connex = ant->connex->next;
	
	if (ant->connex->room_id == anthill->id_end)
	{
		ant->is_in = 0;
		anthill->nb_end++;
	}
	
	print_ant(anthill, tab_ant, i + 1);
}