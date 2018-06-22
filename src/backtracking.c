/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:32:48 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/22 20:36:28 by adhondt          ###   ########.fr       */
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

static int	simule_way(t_pm *w, t_rooms *tube, char *way, int len)
{
	t_rooms *ptr;
	char	*tmp;

	printf("tube->name:%s/|\n", tube->name);
	if (ft_strcmp(tube->name, w->exit) == 0)
	{
	printf("FINISH\n\n");
		if (len < w->len || w->len == -1)
		{
			w->way = ft_strjoin_f(way, "\n", 1);
			w->way = ft_strjoin_f(w->way, tube->name, 1);
			w->len = len;
		}
	}
	else if (first_passage(way, tube->name))
	{
		printf("yayaya\n");
		tmp = ft_strjoin_f(way, "\n", 0);
		tmp = ft_strjoin_f(tmp, tube->name, 1);
		ptr = get_index(w, tube->name);
		simule_way(w, ptr->next_tube, tmp, ++len);
		//free(tmp);
	}
	if (tube->next_tube)
	{
		printf("Plop\n");
		simule_way(w, tube->next_tube, way, len);
	}
	return (0);
}

char	*run_algo(t_pm *w)
{
	int	j;
	char	*way;
	t_rooms *ptr_start;
	t_rooms *ptr_tube;

	j = 0;
	way = NULL;
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
			simule_way(w, ptr_tube, way, 0);
			ptr_tube = ptr_tube->next_tube;
		}
		//free(way);
		if (w->len == -1)
			return (NULL);
	}
	return (w->way);
}

