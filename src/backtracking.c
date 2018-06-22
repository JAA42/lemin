/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:32:48 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/22 16:29:31 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static int	first_passage(char *history, char *room)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (history[i])
	{
		if (history[i] == room[j])
		{
			while (history[i + j] &&
					history[i + j] == room[j] && room[j])
				j++;
			if (room[j] == '\0' &&
					(history[i + j] == '\0' || history[i + j] == '\n'))
				return (0);
			else
				j = 0;
		}
		i++;
	}
	return (1);
}

static t_rooms		*get_index(t_pm *w, char *tube)
{
	t_rooms *ptr;

	ptr = w->first;
	while (ft_strcmp(ptr->name, tube) != 0)
		ptr = ptr->next_room;
	return (ptr);
}

static int	simule_way(t_pm *w, t_rooms *room, t_rooms *tube, char *way, int len)
{
	t_rooms *ptr;

	if (ft_strcmp(tube->name, w->exit) == 0)
	{
		if (len < w->len || w->len == -1)
		{
			//FREE CE QU'IL Y AVAIT DANS w->way maintenant???
				w->way = ft_str3join(way, "\n", tube->name);
				//w->way = ft_strjoin_f(way, "\n", 1);
				//w->way = ft_strjoin_f(w->way, tube->name, 1);
				w->len = len;
				free(way);
		}
	}
	else if (first_passage(way, tube->name))
	{
		//FREE CE QU'IL Y AVAIT DANS w->way maintenant???
		//w->way = ft_strjoin_f(way, "\n", 1);
		//w->way = ft_strjoin_f(w->way, tube->name, 1);
		way = ft_str3join_f(way, "\n", tube->name, 0);
		ptr = get_index(w, tube->name);
		simule_way(w, ptr, ptr->next_tube, way, ++len);
	}
	if (tube->next_tube)
		simule_way(w, room, tube->next_tube, way, len);
	return (0);
}

char	*run_algo(t_pm *w)
{
	int	j;
	char	*way;
	t_rooms *ptr_start;
	t_rooms *ptr_tube;

	j = 0;
	
	if (ft_strcmp(w->entrance, w->exit) == 0)
		return (w->way = ft_strdup_f(w->entrance));
	else
	{
		way = ft_strdup(w->entrance);
		ptr_start = w->first;
		while (ft_strcmp(ptr_start->name, w->entrance) != 0)
		{
			ptr_start = ptr_start->next_room;
		}
		ptr_tube = ptr_start->next_tube;
		while (ptr_tube)
		{
			simule_way(w, ptr_start, ptr_tube, way, 0);
			ptr_tube = ptr_tube->next_tube;
		}
		if (w->len == -1)
			return (NULL);
	}
	return (w->way);
}

