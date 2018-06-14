/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:06:53 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/14 20:42:28 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	init_w(w_pm **w)
{
	*w = (w_pm *)malloc(sizeof(w_pm));

	(*w)->exit = ft_strdup("1");
	(*w)->len = -1;

	(*w)->rooms = (char ***)malloc(sizeof(char **) * 6);
	(*w)->rooms[0] = (char **)malloc(sizeof(char *) * 4);
	(*w)->rooms[1] = (char **)malloc(sizeof(char *) * 4);
	(*w)->rooms[2] = (char **)malloc(sizeof(char *) * 5);
	(*w)->rooms[3] = (char **)malloc(sizeof(char *) * 5);
	(*w)->rooms[4] = (char **)malloc(sizeof(char *) * 1);
	(*w)->rooms[5] = NULL;

	(*w)->rooms[0][0] = ft_strdup("0");
	(*w)->rooms[0][1] = ft_strdup("2");
	(*w)->rooms[0][2] = ft_strdup("3");
	(*w)->rooms[0][3] = NULL;

	(*w)->rooms[1][0] = ft_strdup("1");
	(*w)->rooms[1][1] = ft_strdup("2");
	(*w)->rooms[1][2] = ft_strdup("3");
	(*w)->rooms[1][3] = NULL;

	(*w)->rooms[2][0] = ft_strdup("2");
	(*w)->rooms[2][1] = ft_strdup("0");
	(*w)->rooms[2][2] = ft_strdup("1");
	(*w)->rooms[2][3] = ft_strdup("3");
	(*w)->rooms[2][4] = NULL;

	(*w)->rooms[3][0] = ft_strdup("3");
	(*w)->rooms[3][1] = ft_strdup("2");
	(*w)->rooms[3][2] = ft_strdup("1");
	(*w)->rooms[3][3] = ft_strdup("0");
	(*w)->rooms[3][4] = NULL;

	(*w)->rooms[4] = NULL;
	(*w)->rooms[4][0] = NULL;

}

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
		simule_way(w, get_index(w, w->rooms[i][j]), 1, way, len++);
	}
	else if (w->rooms[i][j + 1] != NULL)
	{
		simule_way(w, get_index(w, w->rooms[i][++j]), 1, way, len);
	}
	return (0);
}

char	*run_algo()
{
	int	j;
	int len = 0;
	char	*way;
	w_pm	*w;

	j = 1;
	init_w(&w);
	way = ft_strdup(w->rooms[0][0]);
	while (w->rooms[0][j])
	{
		simule_way(w, 0, j, way, len);
		j++;
	}
	return (w->way);
}






int	main()
{

	char	*way;

	ft_putstr(run_algo());
	return (0);
}
