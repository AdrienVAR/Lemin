/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:04:06 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/19 11:17:22 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	fill_print_x(t_id *id, intmax_t nb, int size)
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
		if (id->flags[HASH])
			id->print.prec = id->mfw - size - 2;
		else
			id->print.prec = id->mfw - size;
	}
	if (id->mfw > size)
		id->print.space = id->mfw - size - id->print.prec;
	if (id->flags[HASH])
		id->print.space = id->print.space - 2;
}

void	fill_buff_x(t_id *id, t_buff *buff, int size, char charnb[25])
{
	int	i;

	i = -1;
	if (!id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
	i = -1;
	if (id->flags[HASH])
	{
		fill_buff(buff, '0');
		fill_buff(buff, id->type);
	}
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

void	actualize_flags_x(t_id *id, uintmax_t nb)
{
	if (id->flags[MINUS])
		id->flags[ZERO] = 0;
	if (nb == 0)
		id->flags[HASH] = 0;
}

void	print_x(t_id *id, t_buff *buff, uintmax_t nb)
{
	int		i;
	int		lenght;
	char	charnb[25];

	lenght = size_nb_base(nb, 16);
	i = -1;
	if (id->type == 'x')
		nbr_to_str_base(charnb, nb, &i, 16);
	else
		nbr_to_str_base_maj(charnb, nb, &i, 16);
	charnb[lenght] = '\0';
	actualize_flags_x(id, nb);
	fill_print_x(id, nb, lenght);
	fill_buff_x(id, buff, lenght, charnb);
}
