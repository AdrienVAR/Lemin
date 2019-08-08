/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:01:56 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 03:53:44 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		tmp[i] = (*f)(i, (char)s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
