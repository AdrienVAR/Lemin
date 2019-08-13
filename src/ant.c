/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:24:09 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/13 11:06:26 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void create_ant(t_anthill *anthill, t_ant *tab_ant,t_graph *path)
{
	int i;

	anthill->nb_in++;
	i = anthill->nb_in;
	tab_ant[i - 1].id_ant = i;
	tab_ant[i - 1].path = (i - 1) % anthill->nb_path;
	tab_ant[i - 1].connex = path->array[(i - 1) % anthill->nb_path].next;
	tab_ant[i - 1].is_in = 1;
}

void print_all_ant(t_anthill *anthill, t_ant *tab_ant)
{
	int i;
	i =	0;
	while (i < anthill->nb_in)
	{
		ft_putnbr(tab_ant[i].id_ant);
		ft_putstr(": path :");
		ft_putnbr(tab_ant[i].path);
		ft_putstr(": room :");
		ft_putnbr(tab_ant[i].connex->room_id);
		ft_putchar('\n');
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

void	print_ant(t_anthill *anthill, t_ant *tab_ant, int id_ant)
{
	int	id_room;
	id_room = tab_ant[id_ant - 1 ].connex->room_id;

	ft_putchar('L');
	ft_putnbr(id_ant);
	ft_putchar('-');
	ft_putstr(anthill->tab_room[id_room].name);
	ft_putnbr(id_room);
	ft_putchar(' ');
}
