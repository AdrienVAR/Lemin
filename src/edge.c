/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:33:34 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/19 17:53:27 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_edge		*create_edge(t_anthill *anthill)
{
	t_edge	*new_edge;

	if (!(new_edge = (t_edge*)malloc(sizeof(t_edge))))
		error_message(anthill, "MALLOC ERROR\n");
	garbage_collector(&(anthill->head_gar_c), new_edge);
	return (new_edge);
}

/*
**this function look into all room in l_room and look if a room with the same
**name exist.
**If the room already exists, return his len_name
*/

t_room		*is_known_room_get(char *line, t_anthill *anthill)
{
	t_room *actual;

	actual = anthill->l_room;
	while (actual)
	{
		if (!ft_strncmp(line, actual->name,actual->name_len))
			return (actual);
		actual = actual->next;
	}
	return (NULL);
}

int		is_known_room(char *line, t_anthill *anthill)
{
	t_room *actual;

	actual = anthill->l_room;
	while (actual)
	{
		if (!ft_strcmp(line, actual->name))
			return (1);
		actual = actual->next;
	}
	return (0);
}

/*
** check if the current line is a valid edge and return the edge in this case
*/

t_edge		*is_edge(char *line, t_anthill *anthill)
{
	t_room	*room;
	int		len;
	t_edge	*edge;

	edge = create_edge(anthill);
	if (!(room = is_known_room_get(line, anthill)))
		return (NULL);
	len = room->name_len;
	edge->src = room->id;
	if (line[len] != '-')
		return (NULL);
	len++;
	if (!line[len] || !(room = is_known_room_get(line + len, anthill)))
		return (NULL);
	edge->dst = room->id;
	return (edge);
}
