/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:39:14 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 17:53:19 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	tmp = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[len - 1]))
		len--;
	if (i > len)
		i = len;
	if (!(tmp = (char *)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	while (i < len)
	{
		tmp[j++] = s[i++];
	}
	tmp[j] = '\0';
	return (tmp);
}
