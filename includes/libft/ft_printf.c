/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:32:48 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/18 18:33:56 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == '%'
			|| c == 'f');
}

int		choose_function(t_id *id, t_buff *buff, va_list *ap)
{
	if (id->type == 0)
		return (0);
	if (id->type == '%' || id->type == 's' || id->type == 'c'
			|| id->type == 'p')
		get_format_pct_s_c_p(id, buff, ap);
	else if (id->type == 'd' || id->type == 'i')
		get_format_d_i(id, buff, ap);
	else if (id->type == 'u')
		get_format_u(id, buff, ap);
	else if (id->type == 'o' || id->type == 'x' || id->type == 'X')
		get_format_o_x(id, buff, ap);
	else if (id->type == 'f')
		get_format_f(id, buff, ap);
	return (1);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	t_id	id;
	t_buff	buffer;

	va_start(ap, format);
	init_buff(&buffer);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_id(&id);
			set_id(&id, format + i + 1);
			if (!choose_function(&id, &buffer, &ap))
				return (0);
			i += id.len_str + 1;
		}
		else
			fill_buff(&buffer, format[i]);
		i++;
	}
	write(1, buffer.buff, buffer.i);
	return (BUFF_SIZE * buffer.count + buffer.i);
}
