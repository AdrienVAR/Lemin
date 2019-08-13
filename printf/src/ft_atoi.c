/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:15:33 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/29 19:23:40 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i]) - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			res *= 10;
		i++;
	}
	return (res * sign);
}
