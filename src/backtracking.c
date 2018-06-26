/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:56:54 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/26 21:10:55 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static int		define_exit(t_pm *w, int len)
{
	if (len < w->len || w->len == -1)
		w->len = len;
	w->options_info[2] = len;
	return (1);
}

static int		simule_way(t_pm *w, t_rooms *room, int len)
{
	room->weight = len;
	if (ft_strcmp(room->name, w->exit) == 0)
		return (define_exit(w, len));
	room = room->next_tube;
	while (room)
	{
		if (room->passage->weight == 0)
		{
			len++;
			room->weight = len;
			if (simule_way(w, room->passage, len))
				return (1);
			room->passage->weight = -1;
		}
		room = room->next_tube;
	}
	return (0);
}

int				run_algo(t_pm *w)
{
	int		j;
	t_rooms	*ptr_start;

	j = 0;
	if (ft_strcmp(w->entrance, w->exit) == 0)
		return (0);
	ptr_start = w->first;
	while (ft_strcmp(ptr_start->name, w->entrance) != 0)
		ptr_start = ptr_start->next_room;
	ptr_start->weight = 1;
	simule_way(w, ptr_start, 1);
	ptr_start = w->first;
	if (w->len == -1)
		ft_error(4);
	return (1);
}
