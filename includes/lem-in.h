/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:29:38 by advardon          #+#    #+#             */
/*   Updated: 2019/08/07 12:42:59 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"

# define NB_ROOM 10

typedef struct	s_graph
{
	struct s_room 	*room[NB_ROOM];
}				t_graph;

typedef	struct s_room
{
	int				room_id;
	int				value;
	struct s_connexion	*next_con;
}				t_room;

typedef struct s_connexion
{
	int room_id;
	struct s_connexion *next_con;
}	t_connexion;


void	error_message(void);
void    is_visited(t_graph *graph, int id_visited_room);
int		was_visited(t_graph *graph, int id_visited_room);

#endif
