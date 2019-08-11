/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:51:34 by advardon          #+#    #+#             */
/*   Updated: 2019/08/11 11:51:37 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*
void    add_flow(t_anthill *anthill, t_bfs *q)
{
    int id;

    while (id != q->start_room)
    {


    }



//remonte end to start et ajoute 1/-1 dans connex->value

}*/

/*
** Entry point of the algo.
** Implementation of a simplified Edmonds-Karp algorithm.
*/

void    algo(t_anthill *anthill)
{
	t_bfs		q;

    bfs(anthill, &q);
  //  add_flow(anthill, q);
}