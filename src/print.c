/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:47:36 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/13 10:52:07 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*
** Print each round where ants are sent in the anthill.
*/

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
