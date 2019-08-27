/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:13:42 by advardon          #+#    #+#             */
/*   Updated: 2019/08/26 06:51:42 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_usage(void)
{
	ft_putstr("Checker:\n");
	ft_putstr("- Check there are not more that one ant in each room\n");
	ft_putstr("- Describe how many operations were necessary\n");
	ft_putstr("- Print the difference between Lemin and generator\n");
	ft_putstr("Usage: ./checker output.txt or ./checker output.txt ");
	ft_putstr("map_generator.txt\n");
	exit(EXIT_FAILURE);
}

void	print_diff(t_checker *checker)
{
	ft_putstr("Diff with generator :");
	ft_putnbr(checker->operations - checker->diff);
}

int		main(int argc, char **argv)
{
	char		*line;
	t_checker	*checker;

	if (argc == 1)
		print_usage();
	line = NULL;
	checker = init_checker(argv[1]);
	if(!(line = read_map(checker, line)))
		error_mess_pars(checker, "Output error\n", line);
	read_output(checker, line);
	if (argc == 3)
	{
		checker->fd = open_file(argv[2]);
		line = NULL;
		if (!(read_gen_map(checker, line)))
			error_mess_pars(checker, "Error map generator: no number of lines\n", line);
		print_diff(checker);
	}
	get_next_line(-2, &line);
	free_gc(checker->head_gar_c);
	free(checker);
	return (0);
}
