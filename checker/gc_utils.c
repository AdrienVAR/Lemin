/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 05:35:13 by advardon          #+#    #+#             */
/*   Updated: 2019/08/28 12:58:14 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Free all room names once we finished comparing them in a line.
** Head does not record room names and is used for each new round.
*/

void	free_lst(t_room_name **head)
{
	t_room_name	*node;
	t_room_name	*next_node;

	node = *head;
	next_node = node->next;
	node->next = NULL;
}

/*
** Save the adress of each element of a double pointer in the GC.
*/

void	add_tab_garbcoll(t_checker *checker, void **tab)
{
	int i;

	i = 0;
	garbage_collector(&(checker->head_gar_c), tab);
	while (tab[i])
	{
		garbage_collector(&(checker->head_gar_c), tab[i]);
		i++;
	}
}

void	garbage_collector(t_list **head, void *param)
{
	t_list	*new;

	new = ft_lstnew(NULL, 0);
	new->content = param;
	ft_lstadd(head, new);
}

/*
** Free each content (malloc) of the chained list.
** Free each nod of the chaied list.
*/

void	free_gc(t_list *head)
{
	t_list *actual;

	actual = head;
	while (actual)
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
