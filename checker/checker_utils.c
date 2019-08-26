/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:08:46 by advardon          #+#    #+#             */
/*   Updated: 2019/08/22 13:08:49 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_room_name *new_room_name(t_checker *checker)
{
	t_room_name		*new_room;
	if (!(new_room = (t_room_name*)malloc(sizeof(t_room_name))))
		garbage_collector(&(checker->head_gar_c), new_room);
	new_room->room_name = NULL;
	new_room->next = NULL;
	return(new_room);
}

t_checker    *init_checker(char *filename)
{
    t_checker		*checker;
	t_list			*head;

	head = ft_lstnew(NULL, 0);
	if (!(checker = (t_checker*)malloc(sizeof(t_checker))))
		return (0);
	checker->fd = open_file(filename);
	checker->ret = 0;
	checker->operations = 0;
	checker->diff = 0;
	checker->room_end = NULL;
    checker->head_room_op = new_room_name(checker);
	checker->head_gar_c = head;
    return (checker);
}

/*
** Free previous mallocs. Display error message.
*/

void	error_mess(t_checker *checker, char *str)
{
	free_gc(checker->head_gar_c);
	free(checker);
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

int	open_file(char *filename)
{
	int fd;

	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	return (fd);
}

char	*ft_strndupend(const char *s1, size_t n)
{
	int		size;
	char	*tmp;

	size = ft_strlen(s1);
	if (!(tmp = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_memcpy(tmp, s1, n);
	tmp[n] = '\0';
	return (tmp);
}