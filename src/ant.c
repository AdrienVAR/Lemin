/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:24:09 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/13 14:22:55 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"


/*
** Create an ant, assign her ID and her path
*/

void create_ant(t_anthill *anthill, t_ant *tab_ant,t_graph *path, int *path_len)
{
	int i;
	int num_path;
	int	diff_path;

	anthill->nb_in++;
	i = anthill->nb_in;
	tab_ant[i - 1].id_ant = i;
	num_path = (i - 1) % anthill->nb_path;
	while (num_path >= 0)
	{
		diff_path = path_len[num_path] - path_len[0];
		if (tab_ant[i - 1].id_ant < anthill->nb_ant - diff_path)
		{	
			tab_ant[i - 1].path = num_path;
			tab_ant[i - 1].connex = path->array[num_path].next;
			break;
		}
		num_path--;
	}
	//tab_ant[i - 1].connex = path->array[(i - 1) % anthill->nb_path].next;
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

/*
** Move an ant to the next room
*/

void	move_ant(t_anthill *anthill, t_ant *ant)
{
	ant->connex = ant->connex->next;
	if (ant->connex->room_id == anthill->id_end)
	{
		ant->is_in = 0;
		anthill->nb_end++;
	}
}