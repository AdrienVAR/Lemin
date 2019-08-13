/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:18:19 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 10:31:08 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_print_c(t_id *id)
{
	if (id->mfw > 1)
	{
		if (id->flags[ZERO])
			id->print.prec = id->mfw - 1;
		else
			id->print.space = id->mfw - 1;
	}
}

void	fill_buff_c(t_id *id, t_buff *buff, char c)
{
	int i;

	i = -1;
	if (!id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
	i = -1;
	while (++i < id->print.prec)
		fill_buff(buff, '0');
	fill_buff(buff, c);
	i = -1;
	if (id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
}

void	print_c(t_id *id, t_buff *buff, char c)
{
	if (id->flags[MINUS])
		id->flags[ZERO] = 0;
	fill_print_c(id);
	fill_buff_c(id, buff, c);
}
