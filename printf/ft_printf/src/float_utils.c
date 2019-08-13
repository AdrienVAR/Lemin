/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:34:56 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/18 18:55:44 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	split_float(double nb, unsigned int *integral, unsigned int *decimal,
		int *exponent)
{
	double	remainder;

	if (nb < 0.0)
		nb = -nb;
	*exponent = normalize_float(&nb);
	*integral = (unsigned int)nb;
	remainder = nb - *integral;
	remainder *= 1e9;
	*decimal = (unsigned int)remainder;
	remainder -= *decimal;
	if (remainder >= 0.5)
	{
		(*decimal)++;
		if (*decimal >= 1e9)
		{
			*decimal = 0;
			(*integral)++;
			if (*exponent && *integral >= 10)
			{
				(*exponent)++;
				*integral = 1;
			}
		}
	}
}

void	float_unit_rounding(t_buff *buff, unsigned int i, char *charnb)
{
	if (charnb[i + 1] && charnb[i + 1] >= '5' && charnb[i + 1] <= '9')
		fill_buff(buff, charnb[i] + 1);
	else
		fill_buff(buff, charnb[i]);
}

void	fill_buff_dec(t_id *id, t_buff *buff, unsigned int decimal)
{
	unsigned int	l_stock;
	unsigned int	i;
	char			charnb[16];

	if (id->precision == 0)
		return ;
	i = 9;
	while (i-- > 0 && decimal % 10 == 0)
		decimal /= 10;
	l_stock = ++i;
	while (i--)
	{
		charnb[i + 1] = decimal % 10 + '0';
		decimal /= 10;
	}
	charnb[0] = '.';
	i = 0;
	while (i <= l_stock && (short)i <= id->precision - 1)
		fill_buff(buff, charnb[i++]);
	if (i <= l_stock)
		float_unit_rounding(buff, i, charnb);
	else if (i >= l_stock && (short)i <= id->precision)
		while ((short)i++ <= id->precision)
			fill_buff(buff, '0');
}

void	fill_buff_int(t_buff *buff, unsigned int integer)
{
	unsigned int	i;
	unsigned int	lenght;
	unsigned int	l_stock;
	char			charnb[16];

	lenght = size_nb(integer);
	l_stock = lenght;
	while (lenght--)
	{
		charnb[lenght] = integer % 10 + '0';
		integer /= 10;
	}
	i = -1;
	while (++i < l_stock)
		fill_buff(buff, charnb[i]);
}

void	fill_buff_exp(t_buff *buff, int exponent)
{
	if (exponent != 0)
	{
		fill_buff(buff, 'e');
		if (exponent < 0)
		{
			exponent = -exponent;
			fill_buff(buff, '-');
		}
		fill_buff_int(buff, exponent);
	}
}
