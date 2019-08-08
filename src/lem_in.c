/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:51:03 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/08 18:20:34 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/lem-in.h"

static int open_file(char *filename)
{
	int fd;

	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	return (fd);
}


/*
**	check if the line is a valid command and return value corresponding
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
**Read and parse the room part
*/
static	int	read_and_parse_room(int fd, char *line, t_anthill *anthill)
{
	char	**name;
	int		last_cmd;
	int		cmd;

	last_cmd = 0;
 	while ((cmd = num_command(line)) || is_room(line))
	{
		if (is_room(line))
		{
			name = ft_strsplit(line,' ');
			add_room(anthill, name[0], last_cmd);
		}	
		get_next_line(fd,&line);
		last_cmd = cmd; 
	}
	anthill->l_room = anthill->l_room->next;;
	return (1);
}

void	read_and_parse(int fd, t_anthill *anthill)
{
	char	*line;

	if (get_next_line(fd, &line) < 0)
		error_message();
	//check_ant(&line)
	anthill->nb_ant = ft_atoi(line);

	if(get_next_line(fd, &line) < 0)
		error_message();
	read_and_parse_room(fd, line, anthill);
}
	
void	lem_in(char *filename)
{
	int	fd;
	t_anthill	*anthill;

	anthill = init_anthill();	
	if (!(fd = open_file(filename)))
		error_message();
	read_and_parse(fd, anthill);
	print_anthill(anthill);	
}
