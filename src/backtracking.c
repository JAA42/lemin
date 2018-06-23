#include "../inc/lem_in.h"

static int	first_passage(t_hist *history, char *room)
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

static int	simule_way(t_pm *w, t_rooms *room, t_hist *way, int len, int i)
{
	i++;
	/*if (i > 1199)
	{
		ft_putstr(way);
		ft_putstr("plop\n");
		exit(0);
	}*/
	if (ft_strcmp(room->name, w->exit) == 0)
	{
			w->waylist = way;
			w->len = len;
			return (1);
	}
	if (room->next_room)
	{
		room = room->next_tube;
	}
	while (room)
	{
		if (!first_passage(way, room->name))
			;
		else
		{
			way = ft_add_lst(way, room->name);
			if (simule_way(w, get_index(w, room->name), way, ++len, ++i))
				return(1);
		}
		room = room->next_tube;
	}
	return (0);
}

char	*run_algo(t_pm *w)
{
	int	j;
	t_hist	*way;
	t_rooms *ptr_start;
	t_rooms *ptr_tube;

	j = 0;
	way = NULL;
//	if (ft_strcmp(w->entrance, w->exit) == 0)
//		return (w->way = ft_strdup(w->entrance));
//	else
//	{
		ptr_start = w->first;
		while (ft_strcmp(ptr_start->name, w->entrance) != 0)
		{
			ptr_start = ptr_start->next_room;
		}
		ptr_tube = ptr_start->next_tube;
		simule_way(w, ptr_start, way, 0, 0);
		exit (0);
		if (w->len == -1)
			return (NULL);
//	}
	return ("bonjour");
}

