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

static int	simule_way(t_pm *w, t_rooms *room, char *way, int len)
{
	char	*tmp;

	if (ft_strcmp(room->name, w->exit) == 0)
	{
		if (len < w->len || w->len == -1)
		{
			free(w->way);
			w->way = ft_strdup(way);
			w->len = len;
		}
		free(way);
		return (1);
	}
	if (room->next_room)
		room = room->next_tube;
	while (room)
	{
		if (first_passage(way, room->name))
		{
			tmp = ft_strjoin(way, "\n");
			free(way);
			way = ft_strjoin(tmp, room->name);
			free(tmp);
			if (simule_way(w, get_index(w, room->name), ft_strdup(way), ++len))
			{
				free(way);
				return (1);
			}
		}
		room = room->next_tube;
	}
	free(way);
	return (0);
}

char	*run_algo(t_pm *w)
{
	int	j;
//	char	*way;
	t_rooms *ptr_start;

	j = 0;
//	way = ft_strdup("\0");
	if (ft_strcmp(w->entrance, w->exit) == 0)
		return (w->way = ft_strdup(w->entrance));
	ptr_start = w->first;
	while (ft_strcmp(ptr_start->name, w->entrance) != 0)
		ptr_start = ptr_start->next_room;
	simule_way(w, ptr_start, ft_strdup(w->entrance), 0);
	if (w->len == -1)
		return (NULL);
	return ("OK");
}

