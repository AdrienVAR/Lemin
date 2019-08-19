/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:06:40 by advardon          #+#    #+#             */
/*   Updated: 2019/08/19 10:11:59 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*
** Display error message
*/

void	error_message(t_anthill *anthill)
{
	free_gc(anthill->head_gar_c);
	free(anthill);
	write(1, "ERROR\n", 6);
	exit(1);
}

/*
** Print ants on a new line
*/

void	print_ant(t_anthill *anthill, t_ant *tab_ant, int id_ant)
{
	int	id_room;

	id_room = tab_ant[id_ant - 1].connex->room_id;
	ft_putchar('L');
	ft_putnbr(id_ant);
	ft_putchar('-');
	ft_putstr(anthill->tab_room[id_room].name);
	ft_putchar(' ');
}
