/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:29:38 by advardon          #+#    #+#             */
/*   Updated: 2019/08/08 18:20:35 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"


typedef struct	s_graph
{
	struct s_nodes 	*nodes;
	int				nb;
}				t_graph;

typedef	struct s_connexion
{
	int		room_id;
	int		visited;
	struct	s_connexion *next;
}				t_connexion;

typedef struct	s_room
{
	char 	*name;
	int 	id;
	struct	s_room *next;
	int		start;
	int		end;
}				t_room;

typedef struct s_anthill
{
	int			nb_ant;
	int			nb_room;
	t_room		*l_room;
	t_room		*tab_room;
}				t_anthill;

void	error_message(void);


/*
*********************************anthill***************************************
*/
t_anthill	*init_anthill(void);
void		print_anthill(t_anthill *anthill);
/*
**********************************room*****************************************
*/
t_room		*init_room(void);
t_room		*new_room(char *name);
int			add_room(t_anthill *anthill, char *name, int cmd);
int			is_room(char *line);
void		remove_room(t_room **l_room);
/*
*******************************lem-in******************************************
*/
void		lem_in(char *filename);
#endif
