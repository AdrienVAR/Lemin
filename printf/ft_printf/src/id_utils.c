/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:29:50 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/18 18:33:54 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
***********************************GET ID**************************************
** Ces fonctions permettent de recuperer les infos pour une conversion
*/

static void	set_option(t_id *id, char *str, int *i)
{
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == ' ' || str[*i] == '#'
			|| str[*i] == '0')
	{
		if (str[*i] == '-')
			id->flags[0] = 1;
		if (str[*i] == '+')
			id->flags[1] = 1;
		if (str[*i] == '#')
			id->flags[2] = 1;
		if (str[*i] == '0')
			id->flags[3] = 1;
		if (str[*i] == ' ')
			id->flags[4] = 1;
		++*i;
	}
}

void		init_id(t_id *id)
{
	ft_bzero(id->flags, 5);
	ft_bzero(id->format, 2);
	id->mfw = 0;
	id->precision = 0;
	id->type = '0';
	id->print.prec = 0;
	id->print.space = 0;
	id->extra = 0;
	id->len_str = 0;
	id->point = 0;
}

void		set_id(t_id *id, char *str)
{
	int i;

	i = 0;
	init_id(id);
	set_option(id, str, &i);
	id->mfw = ft_atoi(str + i);
	while (str[i] && ft_isdigit(str[i]))
		++i;
	if (str[i] == '.')
	{
		id->precision = ft_atoi(str + (++i));
		id->point = 1;
	}
	else
		id->precision = -1;
	while (str[i] && !is_type(str[i]))
	{
		if (str[i] == 'h' || str[i] == 'l')
			id->format[0] = str[i];
		if (str[i + 1] == str[i])
			id->format[1] = str[i];
		i++;
	}
	id->type = is_type(str[i]) ? str[i] : 0;
	id->len_str = i;
}
