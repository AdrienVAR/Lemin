/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:02:56 by advardon          #+#    #+#             */
/*   Updated: 2019/08/22 13:03:00 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/libft.h"
#include <fcntl.h>

typedef	struct	s_room_name
{
	char					*room_name;
	struct s_room_name		*next;
}				t_room_name;

typedef	struct	s_checker
{
	int				operations;
	int				fd;
    int             ret;
	int				diff;
	char			*room_end;
	t_room_name		*head_room_op;
	t_list			*head_gar_c;
}				t_checker;

/*
*************************************CHECKER**************************************
*/

void	print_diff(t_checker *checker);

/*
*********************************CHECKER_UTILS************************************
*/

t_room_name *new_room_name(t_checker *checker);
t_checker	*init_checker(char *filename);
void		error_mess(t_checker *checker, char *str);
int			open_file(char *filename);
char		*ft_strndupend(t_checker *checker, const char *s1, size_t n);

/*
************************************PARSER*************************************
*/

char		*read_map(t_checker *checker, char *line);
int			read_gen_map(t_checker *checker, char *line);
void		error_mess_pars(t_checker *checker, char *str, char *line);

/*
*********************************READ_OUTPUT*************************************
*/

void		check_room(t_checker *checker, char *line);
void		read_output(t_checker *checker, char *line);

/*
*********************************GC_UTILS*************************************
*/

void		add_tab_garbcoll(t_checker *checker, void **tab);
void		free_lst(t_room_name **head);
void		garbage_collector(t_list **head, void *param);
void		free_gc(t_list *head);

#endif

