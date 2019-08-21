/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:51:03 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/21 16:28:59 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/lem_in.h"

/*
**	Check if the line is a valid command and return value corresponding
** 	to the command
*/

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

/*
***********************Read and Parse Room*************************************
*/

static	int	read_and_parse_room(int fd, char **line, t_anthill *anthill,
								t_buff *buff)
{
	char	**name;
	int		last_cmd;
	int		cmd;

	last_cmd = 0;
	while ((cmd = num_command(*line)) || is_room(anthill, *line))
	{
		if (is_room(anthill, *line))
		{
			if (!(name = ft_strsplit(*line, ' ')))
				error_message_pars(anthill, "MALLOC_ERROR\n", *line);
			add_tab_gc(anthill, (void **)name);
			add_room(anthill, name[0], last_cmd);
			fill_buff_str(buff, *line);
		}
		if (cmd)
			fill_buff_str(buff, *line);
		free(*line);
		if (get_next_line(fd, line) <= 0)
			error_message_eof(anthill, "ERROR\n", *line);
		last_cmd = (cmd != 3) ? cmd : last_cmd;
	}
	if (anthill->id_start == -1 || anthill->id_end == -1)
		error_message_pars(anthill, "ERROR\n", *line);
	return (1);
}

/*
***********************Read and Parse Edge*************************************
*/

void		read_and_parse_edge(int fd, char **line, t_anthill *anthill,
							t_buff *buff)
{
	t_edge	*edge;
	int		ret;
	int 	cmd;
	while ((cmd =num_command(*line)) || (edge = is_edge(*line, anthill)))
	{
		if (edge)
		{
			add_edge(anthill, anthill->graph, edge);
			fill_buff_str(buff, *line);
		}
		if (cmd)
			fill_buff_str(buff, *line);
		free(*line);
		if ((ret = get_next_line(fd, line)) < 0)
			error_message_pars(anthill, "ERROR\n", *line);
		if (ret == 0)
			return ;
		edge = NULL;
	}
	free(*line);
}

/*
*********************Read and Parse Global*************************************
*/

void		read_and_parse(int fd, t_anthill *anthill, t_buff *buff)
{
	char	*line;

	if (get_next_line(fd, &line) <= 0)
		error_message_eof(anthill, "ERROR\n", line);
	while (num_command(line))
	{
		fill_buff_str(buff,line);
		free(line);
		if (get_next_line(fd, &line) <= 0)
			error_message_pars(anthill, "ERROR\n", line);
	}
	if (!check_ant(line))
		error_message_pars(anthill, "ERROR\n", line);
	fill_buff_str(buff, line);
	if ((anthill->nb_ant = ft_atoi(line)) <= 0 || anthill->nb_ant > 100000)
		error_message_pars(anthill, "ERROR\n", line);
	free(line);
	if (get_next_line(fd, &line) <= 0)
		error_message_eof(anthill, "ERROR\n", line);
	read_and_parse_room(fd, &line, anthill, buff);
	if (!is_edge(line, anthill))
		error_message_pars(anthill, "ERROR\n", line);
	create_tab_room(anthill);
	anthill->graph = create_graph(anthill, anthill->nb_room);
	read_and_parse_edge(fd, &line, anthill, buff);
	get_next_line(-2, &line);
}

void		lem_in(int i)
{
	int			fd;
	t_buff		buff;
	t_anthill	*anthill;

	init_buff(&buff);
	anthill = init_anthill(i);
	fd = 0;
	read_and_parse(fd, anthill, &buff);
	if (!bfs(anthill))
		error_message(anthill, "ERROR\n");
	write(1, &buff, buff.i);
	ft_putchar('\n');
	algo(anthill);
	free_gc(anthill->head_gar_c);
	free(anthill);
}
