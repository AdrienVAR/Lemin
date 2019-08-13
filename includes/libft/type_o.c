/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:32:28 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 10:33:36 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			fill_print_o(t_id *id, uintmax_t nb, int size)
{
	if (id->precision == 0 && nb == 0)
	{
		id->print.anything = 0;
		size--;
	}
	else
		id->print.anything = 1;
	if (id->precision <= 0 && id->flags[HASH])
		if (nb != 0 || !id->print.anything)
		{
			id->print.prec = 1;
			id->print.space--;
		}
	if (id->precision > size)
		id->print.prec = id->precision - size;
	else if (id->mfw > size && id->flags[ZERO] && id->precision == -1)
		id->print.prec = id->mfw - size;
	if (id->mfw > size)
		id->print.space = id->mfw - size - id->print.prec;
	if (nb != 0 && id->precision > 0 && id->precision < size && id->flags[HASH])
	{
		id->print.prec++;
		id->print.space--;
	}
}

void			actualize_flags_o(t_id *id)
{
	if (id->flags[MINUS])
		id->flags[ZERO] = 0;
}

void			fill_buff_o(t_id *id, t_buff *buff, int size, char charnb[25])
{
	int	i;

	i = -1;
	if (!id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
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

void			print_o(t_id *id, t_buff *buff, uintmax_t nb)
{
	int		i;
	int		lenght;
	char	charnb[25];

	lenght = size_nb_base(nb, 8);
	i = -1;
	nbr_to_str_base(charnb, nb, &i, 8);
	charnb[lenght] = '\0';
	actualize_flags_o(id);
	fill_print_o(id, nb, lenght);
	fill_buff_o(id, buff, lenght, charnb);
}
