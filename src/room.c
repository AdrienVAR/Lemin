/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:08:54 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/08 17:46:55 by avanhers         ###   ########.fr       */
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
	static int	i = 0;

	i++;
	room = (t_room*)malloc(sizeof(t_room));
	if (room == NULL)
		return (NULL);
	room->next = NULL;
	room->name = name;
	room->id = i;
	room->end = 0;
	room->start = 0;
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
		room->start = 1;
	else if (cmd == 2)
		room->end = 1;
	while (actual->next)
		actual = actual->next;
	actual->next = room;
	anthill->nb_room = room->id;
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

