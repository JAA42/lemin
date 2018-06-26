/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:42:06 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/26 20:49:00 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	free_gps(t_way *first)
{

	while (first)
	{
		free(first->name);
		first = first->next;
	}
	free(first);
}

void		free_rooms_list(t_pm *w)
{
	t_rooms *ptr;
	t_rooms *tmp;
	t_rooms *ptr2;
	t_rooms *tmp2;

	ptr = w->first;
	while (ptr)
	{
		ptr2 = ptr->next_tube;
		while (ptr2)
		{
			free(ptr2->name);
			tmp2 = ptr2->next_tube;
			free(ptr2);
			ptr2 = tmp2;
		}
		free(ptr->name);
		tmp = ptr->next_room;
		free(ptr);
		ptr = tmp;
	}
}

void		free_way_list(t_pm *w)
{
	t_way *ptr;
	t_way *tmp;

	ptr = w->first_way;
	while (ptr)
	{
		free(ptr->name);
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}


