/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:52:26 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/18 14:18:44 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	get_format_pct_s_c_p(t_id *id, t_buff *buff, va_list *ap)
{
	char		*str;
	uintmax_t	nb;

	if (id->type == '%')
		print_pct(id, buff);
	else if (id->type == 's')
	{
		str = va_arg(*ap, char*);
		print_s(id, buff, str);
	}
	else if (id->type == 'c')
	{
		nb = (unsigned char)va_arg(*ap, int);
		print_c(id, buff, nb);
	}
	else if (id->type == 'p')
	{
		nb = (unsigned long)va_arg(*ap, void*);
		print_p(id, buff, nb);
	}
}

void	get_format_d_i(t_id *id, t_buff *buff, va_list *ap)
{
	uintmax_t	nb;

	if (id->format[0] == '\0')
		nb = (int)va_arg(*ap, int);
	if (!ft_strcmp(id->format, "hh"))
		nb = (char)va_arg(*ap, intmax_t);
	if (!ft_strcmp(id->format, "h"))
		nb = (short)va_arg(*ap, intmax_t);
	if (!ft_strcmp(id->format, "l"))
		nb = va_arg(*ap, long);
	if (!ft_strcmp(id->format, "ll"))
		nb = va_arg(*ap, long);
	print_d(id, buff, nb);
}

void	get_format_u(t_id *id, t_buff *buff, va_list *ap)
{
	uintmax_t	nb;

	if (id->format[0] == '\0')
		nb = (unsigned int)va_arg(*ap, unsigned int);
	if (!ft_strcmp(id->format, "hh"))
		nb = (unsigned char)va_arg(*ap, uintmax_t);
	if (!ft_strcmp(id->format, "h"))
		nb = (unsigned short)va_arg(*ap, uintmax_t);
	if (!ft_strcmp(id->format, "l"))
		nb = (unsigned long)va_arg(*ap, unsigned long);
	if (!ft_strcmp(id->format, "ll"))
		nb = (unsigned long)va_arg(*ap, unsigned long);
	print_u(id, buff, nb);
}

void	get_format_o_x(t_id *id, t_buff *buff, va_list *ap)
{
	uintmax_t	nb;

	if (id->format[0] == '\0')
		nb = (unsigned int)va_arg(*ap, unsigned int);
	if (!ft_strcmp(id->format, "hh"))
		nb = (unsigned char)va_arg(*ap, uintmax_t);
	if (!ft_strcmp(id->format, "h"))
		nb = (unsigned short)va_arg(*ap, uintmax_t);
	if (!ft_strcmp(id->format, "l"))
		nb = (unsigned long)va_arg(*ap, unsigned long);
	if (!ft_strcmp(id->format, "ll"))
		nb = (unsigned long)va_arg(*ap, unsigned long);
	if (id->type == 'o')
		print_o(id, buff, nb);
	else
		print_x(id, buff, nb);
}

void	get_format_f(t_id *id, t_buff *buff, va_list *ap)
{
	double	nb;

	nb = (double)va_arg(*ap, double);
	print_f(id, buff, nb);
}
