
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

int	get_index(w_pm *w, char *name)
{
	int	i;

	i = 0;
	while (w->rooms[i] != NULL)
	{
		if (ft_strcmp(name, w->rooms[i][0]) == 0)
			return (i);
		else
			i++;
	}
	return (i);
}

int	simule_way(w_pm *w, int i, int j, char *way, int len)
{
	if (ft_strcmp(w->rooms[i][j], w->exit) == 0)
	{
		if (len < w->len || w->len == -1)
		{
				w->way = ft_str3join(way, "\n", w->rooms[i][j]);//free
				w->len = len;
		}
	}
	else if (first_passage(way, w->rooms[i][j]))
	{
		way = ft_str3join(way, "\n", w->rooms[i][j]);
		simule_way(w, get_index(w, w->rooms[i][j]), 1, way, ++len);
	}
	else if (w->rooms[i][j + 1] != NULL)
		simule_way(w, i, ++j, way, len);
	return (0);
}

char	*run_algo()
{
	int	j;
	int len = 0;
	char	*way;
	w_pm	*w;

	j = 0;
	init_w(&w);
	way = ft_strdup(w->rooms[get_index(w, w->entrance)][0]);
	if (ft_strcmp(w->entrance, w->exit) == 0)
		ft_putstr(w->rooms[0][0]);
	else
		while (w->rooms[get_index(w, w->entrance)][++j])
			simule_way(w, get_index(w, w->entrance), j, way, len);
	return (w->way);
}






int	main()
{

	char	*way;

	ft_putstr(run_algo());
	return (0);
}
