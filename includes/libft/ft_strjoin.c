/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:11:52 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 17:52:55 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	tmp = ft_strnew(len + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_strcpy(tmp, (char *)s1);
	tmp = ft_strcat(tmp, (char *)s2);
	return (tmp);
}
