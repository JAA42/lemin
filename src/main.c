/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:06:53 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/14 19:12:48 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	init_w(w_pm **w)
{
	*w = (w_pm *)malloc(sizeof(w_pm));

	(*w)->exit = ft_strdup("1");

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


int	good_i()
{

}

int	already_pass(char *history, char *way)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (way[i])
	{
		if (way[i] == history[j])
		{
			while(way[i + j] || way[i + j + 1] != '\n')
				j++;
		}
	}
	return (0);
}

int	good_index(t_pm *s, char *name)
{
	while (ft_strcmp(name, )


}

int	simule_way(w_pm *w, int i, int j, char *way, int len)
{
	if (w->rooms[i][j] == NULL)
		return (0); // HEHOOOOOOOOO
	else if (ft_strcmp(w->rooms[i][j], "1") == 0)
	{
		if (len < w->len)
		{
				w->way = ft_strdup(way); //free
				w->len = len;
		}
	}
	if (!already_pass(w->rooms[i][j], way))
	{
		simule_way(w, good_index(s, w->rooms[i][j]), 1, way, len++);
	}
	else
	{
		simule_way(w, i, j++, way, len);
		return (-1);
	}
	return (len);
}

char	*run_algo(char ***rooms)
{
	int	j;
	int len = 0;
	char	*way;
	w_pm	*w;

	j = 1;
	init_w(&w);
	while (rooms[0][j])
	{
		way = ft_strjoin_f(rooms[0][j], "\n", 1);
		simule_way(w, 0, j, way, len);
		j++;
	}
	return (way);

}






int	main()
{

	char	*way;

	ft_putstr(way = run_algo(rooms));
	return (0);
}
