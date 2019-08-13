/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:29:51 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 10:34:17 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_print_u(t_id *id, intmax_t nb, int size)
{
	if (id->point && id->precision == 0 && nb == 0)
	{
		id->print.anything = 0;
		size--;
	}
	else
		id->print.anything = 1;
	if (id->precision > size)
		id->print.prec = id->precision - size;
	else if (id->mfw > size && id->flags[ZERO] && !id->point)
		id->print.prec = id->mfw - size;
	if (id->mfw > size)
		id->print.space = id->mfw - size - id->print.prec;
}

/*
**************flags 0 : - ,  1 : + , 2 : #, 3 : 0 , 4 : space
*/

void	actualize_flags_u(t_id *id)
{
	if (id->flags[MINUS])
		id->flags[ZERO] = 0;
}

void	fill_buff_u(t_id *id, t_buff *buff, int size, char charnb[23])
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

void	print_u(t_id *id, t_buff *buff, intmax_t nb)
{
	int		i;
	int		lenght;
	char	charnb[23];

	lenght = size_nb_base(nb, 10);
	i = -1;
	nbr_to_str_base(charnb, nb, &i, 10);
	charnb[lenght] = '\0';
	actualize_flags_u(id);
	fill_print_u(id, nb, lenght);
	fill_buff_u(id, buff, lenght, charnb);
}
