/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:05:44 by advardon          #+#    #+#             */
/*   Updated: 2019/08/25 14:05:47 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Check for each node if the room name was not previously recorded 
** during this operation.
*/

void	ft_lstadd_end(t_checker *checker, t_room_name *new_node)
{
	t_room_name	*actual;

    if (!(checker->head_room_op->next))
    {
        checker->head_room_op->next = new_node;
        return ;
    }
    actual = checker->head_room_op;
    while (actual->next)
	{
		if(ft_strcmp(actual->next->room_name, new_node->room_name))
        	actual = actual->next;
		else
			error_mess(checker, "Error : two ants in the same room");
	}
    actual->next = new_node;
}

/*
** Before recording a room in a chained list, check if the name is not already
** recorded. End rooms are ignored, they can store multiple ants.
*/

void	cycle_detector(t_checker *checker, char *line, int i)
{
	t_room_name	*actual;
	char 		*content;
	int 		len;
	int 		tmp;

	tmp = i;
	len = 0;
	while(line[i] != ' ' && line[i])
	{
		len++;
		i++;
	}
	content = ft_strndupend(line + tmp, len);
	garbage_collector(&(checker->head_gar_c), content);
	if(ft_strcmp(content, checker->room_end))
	{
		actual = new_room_name(checker);
		actual->room_name = content;
		ft_lstadd_end(checker, actual);
	}
}

/*
** Record each room name in a chained list. Free the list once the line end.
*/

void    check_room(t_checker *checker, char *line)
{
	char	**rooms;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	if (!(rooms = ft_strsplit(line, ' ')))
		error_mess(checker, "MALLOC_ERROR\n");
	add_tab_garbcoll(checker, (void **)rooms);
	while (rooms[i])
	{
		while (rooms[i][pos] != '-' && rooms[i][pos])
			pos++;

		cycle_detector(checker, rooms[i], pos + 1);
		i++;
		pos = 0;
	}
	free_lst(&(checker->head_room_op));
}

/*
** Read Lemin output. Increment operation on each new line;
** Check each room of each line to check if more than 1 ant per room.
*/

void	read_output(t_checker *checker, char *line)
{
	check_room(checker, line);
	checker->operations++;
	free(line);
	while ((checker->ret = get_next_line(checker->fd, &line)) > 0)
	{
		check_room(checker, line);
		checker->operations++;
		free(line);
	}
	ft_putstr("Solved in ");
	ft_putnbr(checker->operations);
	ft_putstr(" operations\n");
}