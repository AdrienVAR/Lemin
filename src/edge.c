/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:33:34 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/09 14:00:43 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_edge		*create_edge(void)
{
	t_edge	*new_edge;
	
	if (!(new_edge = (t_edge*)malloc(sizeof(t_edge))))
		return (NULL);
	return (new_edge);
}




/*
**this function look into all room in l_room and look if a room with the same
**name exist.
**If the room allready exist, return his len_name
*/

t_room		*is_known_room(char *line, t_anthill *anthill)
{
	t_room *actual;

	actual = anthill->l_room;

	while (actual)
	{
		if (!ft_strncmp(line, actual->name, actual->name_len))
			return (actual);
		actual = actual->next;
	}
	return (NULL);
}

/*
** check if the current line is a valid edge and return the edge in this case
*/
t_edge		*is_edge(char *line, t_anthill *anthill)
{
	t_room	*room;
	int		len;
	t_edge	*edge;
	
	edge = create_edge();
	if (!(room = is_known_room(line, anthill)))
		return (NULL);
	len = room->name_len;
	edge->src = room->id;
	if (line[len] != '-')
		return (NULL);
	len++;
	if (!line[len] || !(room = is_known_room(line + len, anthill)))
		return (NULL);
	edge->dst = room->id;
	return (edge);
}
