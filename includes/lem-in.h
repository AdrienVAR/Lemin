/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:29:38 by advardon          #+#    #+#             */
/*   Updated: 2019/08/13 14:10:16 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"

typedef	struct s_connex
{
	int			room_id;
	struct		s_connex *next;
	int			value;
	int			in_path;
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
	int 	in_path;
	int		parent_id;
	int		tmp_parent_id;
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
	int 		id_start;
	int 		id_end;
	int 		nb_in;
	int			nb_end;
	int			nb_path;
	int 		nb_op;
	t_list		*head_gar_c;
}				t_anthill;

typedef	struct s_queue
{
	t_room 		*front;
	t_room 		*rear;
}				t_queue;

typedef	struct	s_ant
{
	int			id_ant;
	int 		is_in;
	t_connex	*connex;
	int			path;
}				t_ant;




/*
*********************************ANTHILL***************************************
*/
t_anthill	*init_anthill(void);
void		print_anthill(t_anthill *anthill);

/*
*********************************GRAPH*****************************************
*/

t_connex	*new_connex(t_anthill *anthill, int dst);
t_graph		*create_graph(t_anthill *anthill, int nb_room);
void		reinit_graph(t_graph *graph);
int			add_edge(t_anthill *anthill, t_graph *graph, t_edge *edge);
int			add_edge_side(t_anthill *anthill, t_graph *graph, int src, int dst);
void		print_graph(t_graph *graph);
void		print_graph2(t_graph *graph);
/*
**********************************ROOM*****************************************
*/

t_room		*init_room(void);
t_room		*new_room(t_anthill *anthill, char *name);
int			add_room(t_anthill *anthill, char *name, int cmd);
int			is_room(t_anthill *anthill, char *line);
int			create_tab_room(t_anthill *anthill);

/*
***********************************EDGE****************************************
*/

t_edge			*create_edge(t_anthill *anthill);
t_room			*is_known_room(char *line, t_anthill *anthill);
t_edge			*is_edge(char *line, t_anthill *anthill);

/*
***********************************BFS******************************************
*/

int 			bfs(t_anthill *anthill);

/*
***********************************ALGO****************************************
*/

void			algo(t_anthill *anthill);
int 			len_path(t_connex *connex);

/*
********************************ALGO_UTILS***************************************
*/

t_room			*get_room(t_anthill *anthill, int id);
int				len_path(t_connex *connex);
int				nb_paths(t_graph *path);
void			sort_path(t_graph *path, int nb_path);

/*
**********************************LEM_IN***************************************
*/

void		lem_in(char *filename);


/*
***********************************PRINT_UTILS**********************************
*/

void		error_message(t_anthill *anthill);

/*
***********************************QUEUE***************************************
*/
t_queue*	createqueue(t_anthill *anthill);
void		enqueue(t_queue *q, t_room *room);
t_room*		dequeue(t_queue *q);

/*
****************************ANT************************************************
*/

void	print_all_ant(t_anthill *anthill, t_ant *tab_ant);
void	print_ant(t_anthill *anthill, t_ant *tab_ant, int id_ant);
void 	create_ant(t_anthill *anthill, t_ant *tab_ant,t_graph *path, int num_path);
void	move_ant(t_anthill *anthill, t_ant *ant, t_ant *tab_ant, int i);

/*
**********************************PRINT****************************************
*/

void 	print_sol(t_anthill * anthill, t_graph *path);
void	print_round(t_anthill *anthill, t_graph *path,t_ant *tab_ant, int *path_len);

/*
********************************PARSING_UTILS***********************************
*/
int 	check_ant(char *line);
int		digit(char *str);
int		open_file(char *filename);
/*
********************************GARBAGE_COLLECTOR***********************************
*/

void    garbage_collector(t_list **head, void *param);
void    free_gc(t_list *head);
void    add_tab_gc(t_anthill *anthill, void **tab);

#endif