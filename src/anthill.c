/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:33:16 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/19 17:53:23 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_anthill	*init_anthill(void)
{
	t_anthill	*anthill;
	t_list		*head;

	head = ft_lstnew(NULL, 0);
	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		error_message(anthill, "MALLOC ERROR\n");
	anthill->nb_ant = 0;
	anthill->nb_room = 0;
	anthill->nb_in = 0;
	anthill->id_start = -1;
	anthill->id_end = -1;
	anthill->nb_end = 0;
	anthill->nb_path = 0;
	anthill->nb_op = 10000000;
	anthill->l_room = NULL;
	anthill->round = 0;
	anthill->head_gar_c = head;
	return (anthill);
}

void		print_anthill(t_anthill *anthill)
{
	int		i;
	t_room	*actual;

	i = 0;
	actual = anthill->l_room;
	while (actual)
	{
		ft_printf("room_name :%s, room_id : %d  start :%d  end :%d\n",
				actual->name, actual->id, actual->start, actual->end);
		actual = actual->next;
	}
	ft_putstr("\n\n");
	while (i < anthill->nb_room)
	{
		if (i == 2232 || i == 2261 || i == 1845 || i == 3409)
		{
			ft_printf("indice : %d  room_name :%s, parent_id : %d"
			"tmp_parent_id : %d, in_path : %d\n", i,
			(anthill->tab_room)[i].name, (anthill->tab_room)[i].
			parent_id, (anthill->tab_room)[i].tmp_parent_id,
			(anthill->tab_room)[i].in_path);
		}
		i++;
	}
}
