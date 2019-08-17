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
	t_list		*head;

	head = ft_lstnew(NULL, 0);
	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (NULL);
	
	anthill->nb_ant = 0;
	anthill->nb_room = 0;
	anthill->nb_in = 0;
	anthill->nb_end = 0;
	anthill->nb_path = 0;
	anthill->l_room = NULL;
	anthill->head_gar_c = head;
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
		if (/*i == 4 || i == 5 || i == 3 || i == 6*/ i==2232 || i == 2261 || i == 1845 || i == 3409 || i == 2231)
		{
		ft_printf("indice : %d  room_name :%s, parent_id : %d tmp_parent_id : %d, in_path : %d\n",
				i, (anthill->tab_room)[i].name, (anthill->tab_room)[i].parent_id,(anthill->tab_room)[i].tmp_parent_id,(anthill->tab_room)[i].in_path);
		}
		i++;
	}
}
