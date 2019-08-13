/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:04:52 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 19:18:13 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

# define BUFF_SIZE 500
# define MINUS 0
# define PLUS 1
# define HASH 2
# define ZERO 3
# define SPACE 4

typedef struct	s_print
{
	int			prec;
	int			space;
	int			anything;
}				t_print;

typedef struct	s_id
{
	char				flags[5];
	char				format[2];
	unsigned short int	mfw;
	short				precision;
	char				type;
	int					extra;
	int					len_str;
	char				point;
	t_print				print;
}				t_id;

typedef struct	s_buff
{
	char		buff[BUFF_SIZE];
	int			i;
	int			count;
}				t_buff;

void			set_id(t_id *id, char *str);
void			init_id(t_id *id);

void			init_buff(t_buff *buff);
void			fill_buff(t_buff *buff, char c);
void			print_d(t_id *id, t_buff *buff, long nb);
void			print_u(t_id *id, t_buff *buff, long nb);
void			print_o(t_id *id, t_buff *buff, uintmax_t nb);
void			print_x(t_id *id, t_buff *buff, uintmax_t nb);
void			print_c(t_id *id, t_buff *buff, char c);
void			print_s(t_id *id, t_buff *buff, char *str);
void			print_p(t_id *id, t_buff *buff, uintmax_t nb);
void			print_pct(t_id *id, t_buff *buff);
void			print_f(t_id *id, t_buff *buff, double nb);
void			split_float(double nb, unsigned int *integral,
										unsigned int *decimal, int *exponent);
void			fill_buff_dec(t_id *id, t_buff *buff, unsigned int decimal);
void			fill_buff_int(t_buff *buff, unsigned int integer);
void			fill_buff_exp(t_buff *buff, int exponent);

void			nbr_to_str(char *str, intmax_t nb, int *i);
void			nbr_to_str_base(char *str, uintmax_t nb, int *i, int base_size);
void			nbr_to_str_base_maj(char *str, uintmax_t nb, int *i,
																int base_size);
int				size_nb(intmax_t nb);
int				size_nb_base(uintmax_t nb, int base_size);

void			get_format_pct_s_c_p(t_id *id, t_buff *buff, va_list *ap);
void			get_format_d_i(t_id *id, t_buff *buff, va_list *ap);
void			get_format_u(t_id *id, t_buff *buff, va_list *ap);
void			get_format_o_x(t_id *id, t_buff *buff, va_list *ap);
void			get_format_f(t_id *id, t_buff *buff, va_list *ap);
int				normalize_float(double *nb);
int				is_type(char c);
int				ft_printf(char *format, ...);
#endif
