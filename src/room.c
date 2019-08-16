/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:08:54 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/09 16:07:53 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"
#include <stdio.h>
t_room			*init_room(void)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	if (room == NULL)
		return (NULL);
	room->next = NULL;
	room->name = "first";
	return (room);
}

t_room			*new_room(char *name)
{
	t_room	*room;
	static int	i = -1;

	i++;
	room = (t_room*)malloc(sizeof(t_room));
	if (room == NULL)
		return (NULL);
	room->next = NULL;
	room->name = name;
	room->name_len = ft_strlen(name);
	room->id = i;
	room->parent_id = -1;
	room->tmp_parent_id = -1;
	room->in_path = 0;
	room->tmp_in_path = 0;
	room->end = 0;
	room->start = 0;
	room->visited = 0;
	
	return (room);
}

int				add_room(t_anthill *anthill, char *name, int cmd)
{
	t_room *room;
	t_room *actual;

	if (!(room = new_room(name)))
		return (0);
	actual = anthill->l_room;
	if (cmd == 1 )
	{
		room->start = 1;
		anthill->id_start = room->id;
	}
	else if (cmd == 2)
	{
		room->end = 1;
		anthill->id_end = room->id;
	}
	room->next = actual;
	anthill->l_room = room;
	anthill->nb_room = room->id + 1;
	return (1);
}

int				is_room(char *str)
{
	int	i;
	char **tab;

	i = 0;

	if (str[i] == 'L')
		return (0);
	else
		tab = ft_strsplit(str,' ');
	while (tab[i])
		i++;
	if (i <= 1)
		return (0);
	return (1);
}


int		create_tab_room(t_anthill *anthill)
{
	int id_room;
	t_room *actual;
	t_room *tmp;

	anthill->tab_room = (t_room*)malloc(sizeof(t_room) * anthill->nb_room);
	if (!anthill->tab_room)
		return (0);
	id_room = anthill->nb_room;
	actual = anthill->l_room;
	while (actual)
	{
		tmp = actual;
		id_room--;
		anthill->tab_room[id_room] = *actual;
		actual = actual->next;
		tmp = NULL;
	}
	return (1);
}
