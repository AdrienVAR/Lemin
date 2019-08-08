/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:33:36 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 17:52:18 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*tmp;

	i = 0;
	if (s == NULL)
		return (NULL);
	tmp = ft_strnew(len);
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[i + start];
		i++;
	}
	return (tmp);
}
