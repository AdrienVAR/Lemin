/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:55:38 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/18 10:33:00 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	nbr_to_str(char *str, intmax_t nb, int *i)
{
	uintmax_t	nbr;

	nbr = nb;
	if (nb == 0)
	{
		str[++*i] = '0';
		return ;
	}
	else if (nb < 0)
		nbr = -nb;
	if (nbr >= 10)
		nbr_to_str(str, nbr / 10, i);
	str[++*i] = (nbr % 10 + '0');
}

int		size_nb(intmax_t nb)
{
	int res;

	res = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		res++;
	}
	return (res);
}

void	nbr_to_str_base(char *str, uintmax_t nb, int *i, int base_size)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb == 0)
	{
		str[++*i] = '0';
		return ;
	}
	if (nb >= (uintmax_t)base_size)
		nbr_to_str_base(str, nb / base_size, i, base_size);
	str[++*i] = (base[nb % base_size]);
}

void	nbr_to_str_base_maj(char *str, uintmax_t nb, int *i, int base_size)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb == 0)
	{
		str[++*i] = '0';
		return ;
	}
	if (nb >= (uintmax_t)base_size)
		nbr_to_str_base_maj(str, nb / base_size, i, base_size);
	str[++*i] = (base[nb % base_size]);
}

int		size_nb_base(uintmax_t nb, int base_size)
{
	int res;

	res = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base_size;
		res++;
	}
	return (res);
}
