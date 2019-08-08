/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:32:34 by advardon          #+#    #+#             */
/*   Updated: 2018/11/22 15:31:17 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(dst);
	i = 0;
	if (len >= size)
		return (size + ft_strlen((char *)src));
	while (*dst && size > 0)
	{
		dst++;
		size--;
	}
	while (src[i] && size > 1)
	{
		*dst = src[i];
		dst++;
		size--;
		i++;
	}
	*dst = '\0';
	return (len + ft_strlen((char *)src));
}
