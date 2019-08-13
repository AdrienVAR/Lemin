/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:51:00 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 10:33:51 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			fill_print_p(t_id *id, int size, uintmax_t nb)
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
	if (id->mfw > id->precision && id->mfw > size)
		id->print.space = id->mfw - size - 2 - id->print.prec;
}

void			fill_buff_p(t_id *id, t_buff *buff, char charnb[25])
{
	int	i;

	i = -1;
	if (!id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
	fill_buff(buff, '0');
	fill_buff(buff, 'x');
	i = -1;
	while (++i < id->print.prec)
		fill_buff(buff, '0');
	i = -1;
	if (id->print.anything)
		while (charnb[++i])
			fill_buff(buff, charnb[i]);
	i = -1;
	if (id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
}

void			actualize_flags_p(t_id *id)
{
	if (id->flags[MINUS])
		id->flags[ZERO] = 0;
}

void			print_p(t_id *id, t_buff *buff, uintmax_t nb)
{
	int		i;
	int		lenght;
	char	charnb[25];

	lenght = size_nb_base(nb, 16);
	i = -1;
	nbr_to_str_base(charnb, nb, &i, 16);
	charnb[lenght] = '\0';
	actualize_flags_p(id);
	fill_print_p(id, lenght, nb);
	fill_buff_p(id, buff, charnb);
}
