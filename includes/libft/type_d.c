/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:54:55 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 12:49:18 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**************flags 0 : - ,  1 : + , 2 : #, 3 : 0 , 4 : space
*/

void	actualize_flags(t_id *id, intmax_t nb)
{
	if (id->flags[MINUS])
		id->flags[ZERO] = 0;
	if (nb < 0)
		id->extra = 2;
	else if (id->flags[PLUS])
		id->extra = 1;
	else if (id->flags[SPACE])
		id->extra = 3;
}

void	fill_print(t_id *id, intmax_t nb, int size)
{
	if (id->precision == 0 && nb == 0)
	{
		id->print.anything = 0;
		size--;
	}
	else
		id->print.anything = 1;
	if (id->precision > size)
		id->print.prec = id->precision - size;
	else if (id->mfw > size && id->flags[ZERO] && id->precision == -1)
	{
		if (id->extra)
			id->print.prec = id->mfw - size - 1;
		else
			id->print.prec = id->mfw - size;
	}
	if (id->mfw > size)
		id->print.space = id->mfw - size - id->print.prec;
	if (id->extra)
		id->print.space--;
}

void	print_extra(t_id *id, t_buff *buff)
{
	if (id->extra)
	{
		if (id->extra == 1)
			fill_buff(buff, '+');
		else if (id->extra == 2)
			fill_buff(buff, '-');
		else
			fill_buff(buff, ' ');
	}
}

/*
**************flags 0 : - ,  1 : + , 2 : #, 3 : 0 , 4 : space
*/

void	fill_buff_d(t_id *id, t_buff *buff, int size, char charnb[23])
{
	int	i;

	i = -1;
	if (!id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
	print_extra(id, buff);
	i = -1;
	while (++i < id->print.prec)
		fill_buff(buff, '0');
	i = -1;
	if (id->print.anything)
		while (++i < size)
			fill_buff(buff, charnb[i]);
	i = -1;
	if (id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
}

void	print_d(t_id *id, t_buff *buff, intmax_t nb)
{
	int		i;
	int		lenght;
	char	charnb[23];

	lenght = size_nb(nb);
	i = -1;
	nbr_to_str(charnb, nb, &i);
	charnb[lenght] = '\0';
	actualize_flags(id, nb);
	fill_print(id, nb, lenght);
	fill_buff_d(id, buff, lenght, charnb);
}
