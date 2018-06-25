/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:56:54 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/25 17:03:02 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void	delete_n(char *way)
{
	int		i;

	i = ft_strlen(way) - 1;
	while (way[i] != '\n')
		i--;
	way[i] = '\0';
}

static int		define_exit(t_pm *w, int len, char *way)
{
	t_rooms			*ptr_start;

	ptr_start = w->first;
	while (ptr_start)
		ptr_start = ptr_start->next_room;
	if (len < w->len || w->len == -1)
	{
		free(w->way);
		w->way = ft_strdup(way);
		w->len = len;
	}
	free(way);
	return (1);
}

static int		simule_way(t_pm *w, t_rooms *room, int len)
{
	static	char	*way;

	room->weight = len;
	if (len == 1)
		way = ft_strdup(w->entrance);
	if (ft_strcmp(room->name, w->exit) == 0)
		return (define_exit(w, len, way));
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

char	*run_algo(t_pm *w)
{
	int		j;
	t_rooms	*ptr_start;

	j = 0;
	if (ft_strcmp(w->entrance, w->exit) == 0 || !w->exit || !w->entrance)
		return (w->way = ft_strdup(w->entrance));
	ptr_start = w->first;
	while (ft_strcmp(ptr_start->name, w->entrance) != 0)
		ptr_start = ptr_start->next_room;
	ptr_start->weight = 1;
	simule_way(w, ptr_start, 1);
	ptr_start = w->first;
	if (w->len == -1)
		return (NULL);
	return ("OK");
}
