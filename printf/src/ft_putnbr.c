/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:46:35 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/19 11:15:35 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_putnbr(int n)
{
	unsigned int	nbr;

	nbr = n;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	if (nbr > 0)
	{
		if (nbr < 10)
			ft_putchar((nbr % 10) + '0');
		else
		{
			ft_putnbr((int)(nbr / 10));
			ft_putchar((nbr % 10) + '0');
		}
	}
}
