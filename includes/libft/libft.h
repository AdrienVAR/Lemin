/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:21:46 by advardon          #+#    #+#             */
/*   Updated: 2019/08/09 11:18:57 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha (int c);
int					ft_isdigit (int c);
int					ft_isalnum(int c);
int					ft_isascii (int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
char				*ft_itoa(int n);
void				ft_putchar (char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_nb_digit(int n);
int					ft_sqrt(int nb);
int					ft_pgcd(int nb1, int nb2);
int					ft_iterative_power(int nb, int power);
char				*ft_strtoupper(char *str);
char				*ft_strtolower(char *str);
void				ft_swap(int *a, int *b);
void				ft_print_words_tables(char **tab);
int					get_next_line(const int fd, char **line);

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define BUFF_SIZE 50000
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

void				set_id(t_id *id, char *str);
void				init_id(t_id *id);

void				init_buff(t_buff *buff);
void				fill_buff(t_buff *buff, char c);
void				fill_buff_str(t_buff *buff, char *str);
void				print_d(t_id *id, t_buff *buff, long nb);
void				print_u(t_id *id, t_buff *buff, long nb);
void				print_o(t_id *id, t_buff *buff, uintmax_t nb);
void				print_x(t_id *id, t_buff *buff, uintmax_t nb);
void				print_c(t_id *id, t_buff *buff, char c);
void				print_s(t_id *id, t_buff *buff, char *str);
void				print_p(t_id *id, t_buff *buff, uintmax_t nb);
void				print_pct(t_id *id, t_buff *buff);
void				print_f(t_id *id, t_buff *buff, double nb);
void				split_float(double nb, unsigned int *integral,
										unsigned int *decimal, int *exponent);
void				fill_buff_dec(t_id *id, t_buff *buff, unsigned int decimal);
void				fill_buff_int(t_buff *buff, unsigned int integer);
void				fill_buff_exp(t_buff *buff, int exponent);

void				nbr_to_str(char *str, intmax_t nb, int *i);
void				nbr_to_str_base(char *str, uintmax_t nb, int *i, int base_size);
void				nbr_to_str_base_maj(char *str, uintmax_t nb, int *i,
																int base_size);
int					size_nb(intmax_t nb);
int					size_nb_base(uintmax_t nb, int base_size);

void				get_format_pct_s_c_p(t_id *id, t_buff *buff, va_list *ap);
void				get_format_d_i(t_id *id, t_buff *buff, va_list *ap);
void				get_format_u(t_id *id, t_buff *buff, va_list *ap);
void				get_format_o_x(t_id *id, t_buff *buff, va_list *ap);
void				get_format_f(t_id *id, t_buff *buff, va_list *ap);
int					normalize_float(double *nb);
int					is_type(char c);
int					ft_printf(char *format, ...);

#endif
