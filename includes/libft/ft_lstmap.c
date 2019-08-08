/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:44:08 by advardon          #+#    #+#             */
/*   Updated: 2018/11/24 17:55:53 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_list;
	t_list	*linker;

	if (!(lst && f))
		return (NULL);
	linker = (0);
	begin_list = (0);
	if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (0);
	begin_list = new;
	linker = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		linker->next = new;
		linker = new;
		lst = lst->next;
	}
	return (begin_list);
}
