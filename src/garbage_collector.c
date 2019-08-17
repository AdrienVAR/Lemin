/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:33:25 by advardon          #+#    #+#             */
/*   Updated: 2019/08/17 14:33:28 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"
/*
void    add_end_lst(t_list **head, t_list *new_node)
{
	//t_list			*actual;

	new_node->next = *head;
    *head= new_node;
}*/

void    garbage_collector(t_list **head, void *param)
{
    t_list  *new;

    new = ft_lstnew(NULL, 0); //if == 1
    new->content = param;
   
    ft_lstadd(head, new);
}

void    free_gc(t_list *head)
{
    t_list *actual;

    actual = head;

    while(actual)
    {
        free(actual->content);
        actual = actual->next;
    }
    actual = head;
    while (head->next)
    {
        actual = head->next;
        free(head);
        head = actual;
    }
    free(head);
}

void    add_tab_gc(t_anthill *anthill, void **tab)
{
    int i;

    i = 0;
    garbage_collector(&(anthill->head_gar_c), tab);
    while (tab[i])
	{
		garbage_collector(&(anthill->head_gar_c), tab[i]);
		i++;
	}
}