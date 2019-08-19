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

t_room	*new_room(t_anthill *anthill, char *name)
{
	t_room		*room;
	static int	i = -1;

	i++;
	room = (t_room*)malloc(sizeof(t_room));
	if (room == NULL)
		return (NULL);
	garbage_collector(&(anthill->head_gar_c), room);
	room->next = NULL;
	room->name = name;
	room->name_len = ft_strlen(name);
	room->id = i;
	room->parent_id = -1;
	room->tmp_parent_id = -1;
	room->in_path = 0;
	room->end = 0;
	room->start = 0;
	room->visited = 0;
	return (room);
}

int		add_room(t_anthill *anthill, char *name, int cmd)
{
	t_room *room;
	t_room *actual;

	if (!(room = new_room(anthill, name)))
		return (0);
	actual = anthill->l_room;
	if (cmd == 1)
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

int		is_room(t_anthill *anthill, char *str)
{
	int		i;
	char	**tab;

	i = 0;
	if (str[i] == 'L')
		return (0);
	else
	{
		tab = ft_strsplit(str, ' ');
		garbage_collector(&(anthill->head_gar_c), tab);
	}
	while (tab[i])
	{
		garbage_collector(&(anthill->head_gar_c), tab[i]);
		i++;
	}
	if (i != 3)
		return (0);
	if (is_known_room(tab[0], anthill) || !digit(tab[1]) || !digit(tab[2]))
		return (0);
	return (1);
}

int		create_tab_room(t_anthill *anthill)
{
	int		id_room;
	t_room	*actual;
	t_room	*tmp;

	anthill->tab_room = (t_room*)malloc(sizeof(t_room) * anthill->nb_room);
	if (!anthill->tab_room)
		return (0);
	garbage_collector(&(anthill->head_gar_c), anthill->tab_room);
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
