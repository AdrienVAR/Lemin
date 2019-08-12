/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:24:09 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/12 17:01:09 by avanhers         ###   ########.fr       */
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


void	print_ant(t_anthill *anthill, t_ant *tab_ant, int id_ant)
{
	int	id_room;
 	(void)anthill;
	id_room = tab_ant[id_ant - 1 ].connex->room_id;
	ft_putchar('L');
	ft_putnbr(id_ant);
	ft_putchar('-');
	ft_putstr(anthill->tab_room[id_room].name);
	ft_putnbr(id_room);
	ft_putchar(' ');
}
