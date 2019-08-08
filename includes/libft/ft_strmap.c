/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:47:31 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 03:54:47 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	if (s == 0)
		return (0);
	len = ft_strlen((char *)s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	while (s[i] != '\0')
	{
		tmp[i] = (*f)((char)s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
