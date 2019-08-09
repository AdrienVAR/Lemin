/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:33:16 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/08 16:42:17 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"
#include <stdio.h>

t_anthill	*init_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (NULL);
	anthill->nb_ant = 0;
	anthill->nb_room = 0;
	anthill->l_room = init_room();
	return (anthill);
}

void	print_anthill(t_anthill *anthill)
{
	t_room *actual;

	actual = anthill->l_room;
	while (actual)
	{
		printf("room_name :%s, room_id : %d  start :%d  end :%d\n",
				actual->name, actual->id, actual->start,actual->end);
		actual = actual->next;
	}
}