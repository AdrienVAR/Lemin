/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:45:16 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 10:34:08 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_print_s(t_id *id, int size)
{
	if (id->precision > 0 && id->precision < size)
		id->print.prec = id->precision;
	else if (id->precision == 0)
		id->print.prec = 0;
	else
		id->print.prec = size;
	if (id->mfw > id->print.prec)
		id->print.space = id->mfw - id->print.prec;
}

void	fill_buff_s(t_id *id, t_buff *buff, char *str)
{
	int i;

	i = -1;
	if (!id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
	i = -1;
	while (++i < id->print.prec)
		fill_buff(buff, str[i]);
	i = -1;
	if (id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
}

void	print_s(t_id *id, t_buff *buff, char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (id->flags[MINUS])
		id->flags[ZERO] = 0;
	fill_print_s(id, len);
	fill_buff_s(id, buff, str);
}
