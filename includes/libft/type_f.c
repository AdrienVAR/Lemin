/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:52:29 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/19 11:26:18 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	actualize_flags_f(t_id *id, double nb)
{
	if (id->precision == -1)
		id->precision = 6;
	id->extra = 0;
	if (id->flags[MINUS] || id->flags[PLUS])
		id->flags[ZERO] = 0;
	if (nb < 0.0)
		id->extra = 2;
	if (id->flags[ZERO])
		id->flags[SPACE] = 0;
	if (id->flags[PLUS])
	{
		id->flags[SPACE] = 0;
		id->extra = 1;
	}
	else if (id->flags[SPACE])
		id->extra = 3;
}

void	print_spaces(t_id *id, t_buff *buff, unsigned int size_int, int exp)
{
	int	i;
	int	stock;

	i = exp >= 0.0 ? 1 : 2;
	stock = id->precision + size_int + i;
	if (id->flags[PLUS] || id->flags[SPACE])
		stock++;
	if (stock < id->mfw)
	{
		i = 0;
		while (++i <= id->mfw - stock - 1)
		{
			if (id->flags[ZERO])
				fill_buff(buff, '0');
			else
				fill_buff(buff, ' ');
		}
		if (id->flags[ZERO] && id->extra != 2)
			fill_buff(buff, '0');
		else if (id->flags[PLUS] || id->flags[SPACE] || id->extra == 0)
			fill_buff(buff, ' ');
	}
}

void	print_extra_f(t_id *id, t_buff *buff, double *nb)
{
	if (id->flags[PLUS] && *nb >= 0.0)
		fill_buff(buff, '+');
	if (id->flags[SPACE] && *nb >= 0.0)
		fill_buff(buff, ' ');
	if (*nb < 0.0)
	{
		*nb = -*nb;
		fill_buff(buff, '-');
	}
}

void	print_f(t_id *id, t_buff *buff, double nb)
{
	unsigned int	integral;
	unsigned int	decimal;
	int				exponent;

	actualize_flags_f(id, nb);
	split_float(nb, &integral, &decimal, &exponent);
	if (id->flags[ZERO] && nb < 0.0)
	{
		fill_buff(buff, '-');
		nb = -nb;
	}
	if (!id->flags[MINUS])
		print_spaces(id, buff, size_nb(integral), exponent);
	print_extra_f(id, buff, &nb);
	if (id->precision == 0 && (unsigned int)(nb * 10) % 10 >= 5)
		integral++;
	fill_buff_int(buff, integral);
	fill_buff_dec(id, buff, decimal);
	fill_buff_exp(buff, exponent);
	if (id->flags[HASH] && id->precision == 0)
		fill_buff(buff, '.');
	if (id->flags[MINUS])
		print_spaces(id, buff, size_nb(integral), exponent);
}
