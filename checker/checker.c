/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:13:42 by advardon          #+#    #+#             */
/*   Updated: 2019/08/21 17:25:58 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

//recupérer la veleur de end pour exception su strcmp

void	free_lst(t_room_name **head)
{
    t_room_name           *node;
    t_room_name           *next_node;

	node = *head;
	next_node = node->next;
	node->next = NULL; //we reuse head, so put it to null after use
    node = next_node;
    while (node)
    {
       	next_node = node->next;
        free(node->room_name);
        free(node);
        node = next_node;
    }
}

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

char	*add_end_room(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	if (str[i] == 'L')
		return (0);
	else
	{
		if (!(tab = ft_strsplit(str, ' ')))
			error_mess("MALLOC ERROR\n");
		//garbage_collector(&(anthill->head_gar_c), tab);
	}
	/*while (tab[i])
	{
		garbage_collector(&(anthill->head_gar_c), tab[i]);
		i++;
	}*/
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
			checker->room_end = add_end_room(line);
		last_cmd = (cmd != 3) ? cmd : last_cmd;
		if (line[0] == 'L')
		{
			if(checker->room_end == NULL)
				error_mess("Error : No end room");
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
				return (1);
			}
		free(line);
	}
	return (0);
}

void	print_diff(t_checker *checker)
{
	ft_putstr("Diff with generator :");
	ft_putnbr(checker->diff - checker->operations);
}

int main(int argc, char **argv)
{
	char	*line;
	t_checker *checker;

	if (argc == 1)
	{
		ft_putstr("Checker: Check if there are no more that one ant in each room\n");
		ft_putstr("Describe how many operations were necessary\n");
		ft_putstr("Usage: ./checker output.txt or ./checker output.txt map_generator.txt\n");
	}
	line = NULL;
	checker = init_checker(argv[1]);
	line = read_map(checker, line);
	if(line == NULL)
		return (0);
	read_output(checker, line);
	if (argc == 3)
	{
		checker->fd = open_file(argv[2]);
		line = NULL;
		if (!(read_gen_map(checker, line)))
			error_mess("Error map generator: no number of lines required");
		print_diff(checker);
	}
	return (0);
}
