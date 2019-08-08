/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 05:59:31 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 17:35:28 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pgcd(int nb1, int nb2)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (nb1 < 0 || nb2 < 0)
		return (0);
	if (nb1 == 0 || nb2 == 0)
		return (0);
	if (nb1 == nb2)
		return (nb1);
	while (i <= nb1 && i <= nb2)
	{
		if ((nb1 % i == 0) && (nb2 % i == 0))
			result = i;
		i++;
	}
	return (result);
}
