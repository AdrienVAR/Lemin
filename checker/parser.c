/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 05:22:12 by advardon          #+#    #+#             */
/*   Updated: 2019/08/26 05:22:15 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	num_command(char *line)
{
	if (!(ft_strcmp(line, "##start")))
		return (1);
	else if (!(ft_strcmp(line, "##end")))
		return (2);
	else if (line[0] == '#')
		return (3);
	return (0);
}

static char	*add_end_room(t_checker *checker, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	if (str[i] == 'L')
		return (0);
	else
	{
		if (!(tab = ft_strsplit(str, ' ')))
			error_mess(checker, "MALLOC ERROR\n");
        add_tab_garbcoll(checker, (void **)tab);
	}
	return (tab[i]);
}

char	*read_map(t_checker *checker, char *line)
{
	int		last_cmd;
	int		cmd;

	last_cmd = 0;
	while ((checker->ret = get_next_line(checker->fd, &line)) > 0)
	{
		cmd = num_command(line);
		if(last_cmd == 2 && cmd == 0)
			checker->room_end = add_end_room(checker, line);
		last_cmd = (cmd != 3) ? cmd : last_cmd;
		if (line[0] == 'L')
		{
			if(checker->room_end == NULL)
				error_mess(checker, "Error : No end room");
			return (line);
		}
		free(line);
	}
	return (0);
}

int	read_gen_map(t_checker *checker, char *line)
{
	while ((checker->ret = get_next_line(checker->fd, &line)) > 0)
	{
		if (num_command(line) == 3)
			if (!(ft_memcmp(line, "#Here is the number of lines required: ", 39)))
			{
				checker->diff = ft_atoi(line + 39);
                free(line);
				return (1);
			}
		free(line);
	}
    free(line);
	return (0);
}