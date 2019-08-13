/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:28:46 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/19 11:15:41 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = n;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	if (nbr > 0)
	{
		if (nbr < 10)
			ft_putchar_fd((nbr % 10) + '0', fd);
		else
		{
			ft_putnbr_fd((int)(nbr / 10), fd);
			ft_putchar_fd((nbr % 10) + '0', fd);
		}
	}
}
