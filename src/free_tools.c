/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:42:06 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/27 11:11:22 by avallois         ###   ########.fr       */
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

t_way			*free_ant_sender(t_way *tmp)
{
	t_way	*tmp2;

	free(tmp->name);
	tmp2 = tmp->next;
	free(tmp);
	tmp = tmp2;
	return (tmp);
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


