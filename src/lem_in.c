/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:51:03 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/12 13:53:34 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/lem-in.h"

/*
**	Check if the line is a valid command and return value corresponding
** 	to the command
*/

static int num_command(char *line)
{
	if (!(ft_strcmp(line, "##start")))
		return (1);
	else if (!(ft_strcmp(line, "##end")))
		return (2);
	else if (line[0] == '#')
		return (3);
	return (0);
}

/*
***********************Read and Parse Room*************************************
*/

static	int	read_and_parse_room(int fd, char **line, t_anthill *anthill,t_buff *buff)
{
	char	**name;
	int		last_cmd;
	int		cmd;

	last_cmd = 0;
 	while ((cmd = num_command(*line)) || is_room(anthill, *line))
	{
		if (is_room(anthill, *line))
		{
			name = ft_strsplit(*line,' ');
			add_tab_gc(anthill, (void **)name);
			add_room(anthill, name[0], last_cmd);
			fill_buff_str(buff, *line);
		}	
		if (cmd == 2 || cmd == 1)
			fill_buff_str(buff, *line);
		free(*line);
		get_next_line(fd, line);
		last_cmd = cmd; 
	}
	return (1);
}

/*
***********************Read and Parse Edge*************************************
*/

void	read_and_parse_edge(int fd, char **line, t_anthill *anthill, t_buff *buff)
{
	t_edge	*edge;


	while (num_command(*line) || (edge = is_edge(*line, anthill)))
	{
		if (edge)
		{
			add_edge(anthill, anthill->graph,edge);
			fill_buff_str(buff, *line);
		}
		free(*line);
		if (get_next_line(fd, line) < 0)
			return;
		edge = NULL;
	}
	//free(line);
}

/*
*********************Read and Parse Global*************************************
*/

void	read_and_parse(int fd, t_anthill *anthill,t_buff *buff)
{
	char	*line;

	if (get_next_line(fd, &line) < 0)
		error_message(anthill);
	if (!check_ant(line))
		error_message(anthill);
	fill_buff_str(buff, line);
	anthill->nb_ant = ft_atoi(line);
	free(line);
	if(get_next_line(fd, &line) < 0)
		error_message(anthill);
	read_and_parse_room(fd, &line, anthill, buff);
	if (!is_edge(line, anthill))
	{
		free(line);
		error_message(anthill);
	}
	create_tab_room(anthill);	
	anthill->graph = create_graph(anthill, anthill->nb_room);
	read_and_parse_edge(fd, &line, anthill, buff);
	free(line);
	write(1, buff, buff->i);
	get_next_line(-2, &line);
//	free(line);
}
	
void	lem_in(char *filename)
{
	int	fd;
	t_buff buff;
	t_anthill	*anthill;

	init_buff(&buff);
	anthill = init_anthill();	
	if (!(fd = open_file(filename)))
		error_message(anthill);
	read_and_parse(fd, anthill, &buff);
	//print_anthill(anthill);
	ft_putchar('\n');
	algo(anthill);
	free_gc(anthill->head_gar_c);
	free(anthill);
}
