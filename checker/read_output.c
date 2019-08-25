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
		if(ft_strcmp(actual->next->room_name, new_node->room_name)) //compare content of each node
        	actual = actual->next;
		else
			error_mess("Error : two ants in the same room");
	}
    actual->next = new_node;
}

void	cycle_detector(t_checker *checker, char *line, int i)
{
	t_room_name	*actual;
	char 		*content;
	int 		len;
	int 		tmp;

	tmp = i;
	len = 0;
	while(line[i] != ' ' && line[i])//|| line[i] != '\n' no need \n, there is a space)
	{
		len++;
		i++;
	}
	//if (!(content = (char *)malloc(sizeof(char) * (len + 1))))
	//	error_mess("ERROR MALLOC");
	content = ft_strndupend(line + tmp, len);
	if(ft_strcmp(content, checker->room_end)) //if other that 0, we add in list
	{
		actual = new_room_name();
		actual->room_name = content;
		ft_lstadd_end(checker, actual);
	}
}

void    check_room(t_checker *checker, char *line) //Faire un ft_strsplit plutot que manipuler la line.
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	while(i < len)
	{
		while(line[i] != '-' && i < len)
			i++;
		while(line[i + j] != ' ' && (i + j) < len) 
		{
			i++;
			/*if(line[i + j] == '-' && (i + j) < len)
			{
				i = i + j;
				j = 0;
			}*/
			ft_putchar(line[i + j]);
			cycle_detector(checker, line, i + j);
			j++;
		}
		j = 0;
		ft_putchar ('\n');
	}
	free_lst(&(checker->head_room_op));
}

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