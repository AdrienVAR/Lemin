/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:54:05 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 04:15:40 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		if ((*(unsigned char*)s1) != (*(unsigned char*)s2))
		{
			return ((*(unsigned char*)s1) - (*(unsigned char*)s2));
		}
		n--;
		s1++;
		s2++;
	}
	return (0);
}
