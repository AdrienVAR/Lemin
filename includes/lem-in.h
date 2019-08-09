/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:29:38 by advardon          #+#    #+#             */
/*   Updated: 2019/08/09 14:25:00 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"

typedef	struct s_connex
{
	int			room_id;
	struct		s_connex *next;
}				t_connex;

typedef struct			s_graph
{
	struct s_connex 	 *array;
	int					nb_room;
}						t_graph;


typedef struct			s_edge
{
	int					src;
	int					dst;
}						t_edge;

typedef struct	s_room
{
	char 	*name;
	int		name_len;
	int 	id;
	struct	s_room *next;
	int		start;
	int		end;
	int 	visited;
}				t_room;

typedef struct s_anthill
{
	int			nb_ant;
	int			nb_room;
	t_room		*l_room;
	t_room		*tab_room;
	t_graph		*graph;
}				t_anthill;

void	error_message(void);


/*
*********************************ANTHILL***************************************
*/
t_anthill	*init_anthill(void);
void		print_anthill(t_anthill *anthill);

/*
*********************************GRAPH*****************************************
*/

t_connex	*new_connex(int dst);
t_graph		*create_graph(int nb_room);
int			add_edge(t_graph *graph, t_edge *edge);
void		print_graph(t_graph *graph);
/*
**********************************ROOM*****************************************
*/

t_room		*init_room(void);
t_room		*new_room(char *name);
int			add_room(t_anthill *anthill, char *name, int cmd);
int			is_room(char *line);
void		remove_room(t_room **l_room);

/*
***********************************EDGE****************************************
*/

t_edge			*create_edge(void);
t_room			*is_known_room(char *line, t_anthill *anthill);
t_edge			*is_edge(char *line, t_anthill *anthill);

/*
*******************************LEM_IN******************************************
*/
void		lem_in(char *filename);
#endif
