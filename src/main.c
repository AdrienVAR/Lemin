/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:41:23 by advardon          #+#    #+#             */
/*   Updated: 2019/08/28 11:42:27 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "-path"))
		{
			lem_in(1);
		}
		else if (!ft_strcmp(argv[1], "-edge"))
		{
			lem_in(2);
		}
		else
		{
			ft_putstr("Usage: < map launch program\n");
			ft_putstr("< arg -path : see valid paths\n");
			ft_putstr("< arg -edge : visualize edges");
		}
		return (0);
	}
	lem_in(0);
	return (0);
}
