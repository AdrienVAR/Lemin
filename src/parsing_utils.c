/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:31:47 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/28 11:43:15 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	is_integer(char *str)
{
	int		len;
	char	signe;

	signe = '+';
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		signe = '-';
		len--;
	}
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else
	{
		if (signe == '+' && ft_strcmp(str, "2147483647") > 0)
			return (0);
		else if (signe == '-' && ft_strcmp(str + 1, "2147483648") > 0)
			return (0);
		else
			return (1);
	}
}

int	check_ant(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	if (line[0] == '+' || line[0] == '-')
		line++;
	while (line[0] == '0')
		line++;
	if (digit(line))
	{
		if (is_integer(line))
			return (1);
	}
	if ((line[0] == '+' || line[0] == '-') && digit(line + 1))
	{
		if (is_integer(line))
			return (1);
	}
	return (0);
}

int	digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
