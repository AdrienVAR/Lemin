/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:25:45 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 10:36:05 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_buff(t_buff *buff)
{
	ft_bzero(buff->buff, BUFF_SIZE);
	buff->i = 0;
	buff->count = 0;
}

void	print_full_buff(t_buff *buff)
{
	write(1, buff->buff, BUFF_SIZE);
	ft_bzero(buff->buff, BUFF_SIZE);
	buff->count++;
	buff->i = 0;
}

void	fill_buff(t_buff *buffer, char c)
{
	if (buffer->i == BUFF_SIZE)
		print_full_buff(buffer);
	buffer->buff[buffer->i] = c;
	buffer->i++;
}

void	fill_buff_str(t_buff *buffer, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		fill_buff(buffer, str[i]);
	fill_buff(buffer, '\n');
}
