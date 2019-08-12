/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:33:16 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/12 17:05:43 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"
#include <stdio.h>
/*
void		free_graph(t_graph *graph)
{
	int i;

	i = 1;
	while (graph->array[i])
	{	

		i++;
	}
}

void		free_anthill(t_anthill *anthill)
{
	free_graph(anthill->graph);
}
*/
t_anthill	*init_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (NULL);
	anthill->nb_ant = 0;
	anthill->nb_room = 0;
	anthill->nb_in = 0;
	anthill->nb_end = 0;
	anthill->nb_path = 0;
	anthill->l_room = NULL;
	return (anthill);
}

void	print_anthill(t_anthill *anthill)
{
	int	i;
	/*t_room *actual;
	
	actual = anthill->l_room;
	while (actual)
	{
		printf("room_name :%s, room_id : %d  start :%d  end :%d\n",
				actual->name, actual->id, actual->start, actual->end);
		actual = actual->next;
	}*/
	ft_putstr("\n\n");
	i = 0;
	while (i < anthill->nb_room)
	{
		printf("indice : %d  room_name :%s, parent_id : %d\n",
				i, (anthill->tab_room)[i].name, (anthill->tab_room)[i].parent_id);
		i++;
	}
}
