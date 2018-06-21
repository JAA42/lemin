
#include "../inc/lem_in.h"

int	first_passage(char *history, char *room)
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

t_rooms		*get_index(w_pm *w, char *tube)
{
	t_rooms *ptr;

	ptr = w->first;
	while (ft_strcmp(ptr->name, tube) != 0)
		ptr = ptr->next_room;
	return (ptr);
}

int	simule_way(w_pm *w, t_rooms *room, t_rooms *tube, char *way, int len)
{
	t_rooms *ptr;

	if (ft_strcmp(tube->name, w->exit) == 0)
	{
		if (len < w->len || w->len == -1)
		{
				w->way = ft_str3join(way, "\n", tube->name);
				w->len = len;
				free(way);
		}
	}
	else if (first_passage(way, tube->name))
	{
		way = ft_str3join_f(way, "\n", tube->name, 0);
		ptr = get_index(w, tube->name);
		simule_way(w, ptr, ptr->next_tube, way, ++len);
	}
	else if (tube->next_tube)
		simule_way(w, room, tube->next_tube, way, len);
	return (0);
}

char	*run_algo(w_pm *w)
{
	int	j;
	char	*way;
	t_rooms *ptr_start;
	t_rooms *ptr_t;

	j = 0;
	if (ft_strcmp(w->entrance, w->exit) == 0)
		return (w->way = ft_strdup_f(w->entrance));
	else
	{
		way = ft_strdup(w->entrance);
		ptr_start = w->first;
		while (ft_strcmp(ptr_start->name, w->entrance))
		{
			ptr_start = ptr_start->next_room;
		}
		ptr_t = ptr_start->next_tube;
		while (ptr_t)
		{
			simule_way(w, ptr_start, ptr_t, way, 0);
			ptr_t = ptr_t->next_tube;
		}
		if (ft_strcmp(w->way, w->entrance) == 0)
			return (NULL);
	}
	return (w->way);
}

int	main()
{
	w_pm	*w;

	init_w(&w);
	get_input(w);
	 if (!run_algo(w))
	 {
		 ft_putstr("No way\n");
		exit(0);
	}
	send_ants(ft_split_n(w->way), ft_count_char(w->way, '\n') + 1);
	return (0);
}
