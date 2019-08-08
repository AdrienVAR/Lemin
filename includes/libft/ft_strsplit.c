/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:54:35 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 17:53:55 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *str, char c)
{
	int i;
	int nb;
	int bool;

	i = 0;
	nb = 0;
	bool = 1;
	while ((str[i]) == c)
		i++;
	while (str[i] != '\0')
	{
		if ((str[i]) == c)
		{
			bool = 1;
		}
		else if ((str[i] != c) && bool == 1)
		{
			bool = 0;
			nb++;
		}
		i++;
	}
	return (nb);
}

static int		ft_word_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while ((s[i] != c) && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void		ft_cut_ref(char const *str, char **ptr, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i < ft_words(str, c))
	{
		k = 0;
		ptr[i] = ft_strnew(ft_word_len(&str[j], c) + 1);
		if (ptr[i] == 0)
			return ;
		while ((str[j]) == c)
			j++;
		while ((str[j]) != c && str[j])
		{
			ptr[i][k] = str[j];
			j++;
			k++;
		}
		ptr[i][k] = '\0';
		i++;
	}
	ptr[i] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char **)malloc(sizeof(*ptr) * (ft_words(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	ft_cut_ref(s, ptr, c);
	return (ptr);
}
