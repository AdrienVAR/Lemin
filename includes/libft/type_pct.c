/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:24:06 by avanhers          #+#    #+#             */
/*   Updated: 2019/07/18 10:34:00 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_print_pct(t_id *id)
{
	if (id->mfw > 1)
		id->print.space = id->mfw - 1;
}

void	print_pct(t_id *id, t_buff *buff)
{
	int i;

	i = -1;
	fill_print_pct(id);
	if (!id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
	fill_buff(buff, '%');
	if (id->flags[MINUS])
		while (++i < id->print.space)
			fill_buff(buff, ' ');
}
