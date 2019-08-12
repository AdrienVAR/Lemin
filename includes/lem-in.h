/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:29:38 by advardon          #+#    #+#             */
/*   Updated: 2019/08/12 13:41:12 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"

# define NB_ROOM 10
typedef	struct s_connex
{
	int			room_id;
	struct		s_connex *next;
	int			value;
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
	int		parent_id;
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
}				t_anthill;

typedef struct s_bfs
{
	t_connex	*connex;
	int			bfs_round;
	int 		que_in[NB_ROOM];
    int 		que_out[NB_ROOM];
    int 		room_que_out;
    int 		room_que_in;
	int			start_room;
    int 		end_room;
    int 		end_bfs;
    int 		que_len;
}				t_bfs;


typedef	struct s_queue
{
	t_room *front;
	t_room *rear;
}				t_queue;






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
int			add_edge_side(t_graph *graph, int src, int dst);
void		print_graph(t_graph *graph);
/*
**********************************ROOM*****************************************
*/

t_room		*init_room(void);
t_room		*new_room(char *name);
int			add_room(t_anthill *anthill, char *name, int cmd);
int			is_room(char *line);
int			create_tab_room(t_anthill *anthill);

/*
***********************************EDGE****************************************
*/

t_edge			*create_edge(void);
t_room			*is_known_room(char *line, t_anthill *anthill);
t_edge			*is_edge(char *line, t_anthill *anthill);

/*
***********************************BFS****************************************
*/

int bfs(t_anthill *anthill);
void    		update_queue(int *que_in, int *que_out);
void			init_room_queue(int *queue);
void			init_queue(t_anthill *anthill, t_bfs *q);

/*
***********************************ALGO**************************************
*/

void			algo(t_anthill *anthill);

/*
********************************BFS_UTIL**************************************
*/

void    		is_visited (t_anthill *anthill, int id_visited_room, int parent_id);
int				was_visited(t_anthill *anthill, int id_room);
int				start_id(t_anthill *anthill);
int				end_id(t_anthill *anthill);

/*
**********************************LEM_IN***************************************
*/
void		lem_in(char *filename);


/*
***********************************PRINT_UTILS**********************************
*/

void		error_message(void);

t_queue* createqueue();
void enqueue(t_queue *q, t_room *room);
t_room* dequeue(t_queue *q);
void print_queue(t_queue *q);





#endif
