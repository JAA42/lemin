/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:06:53 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/14 18:22:24 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int	good_i()
{

}

int	already_pass(char *history, char *way)
{

	return (0);
}

int	good_index(t_pm *s, char *name)
{
	while (ft_strcmp(name, )


}

int	simule_way(char ***rooms, int i, int j, char *way, int len)
{
	if (rooms[i][j] == NULL)
		return (0);
	else if (is_exit(rooms[i][j]))
	{
		if (len < s->len)
		{
			//	s->way = ft_strdup(way);
			//	s->len = len;
		}
	}
	if (!already_pass(rooms[i][j], way))
	{
		simule_way(rooms, good_index(s, rooms[i][j]), 1, way, len++);
	}
	else
	{
		simule_way(rooms, i, j++, way, len);
		return (-1);
	}
	return (len);
}

char	*run_algo(char ***rooms)
{
	int ref;
	int	i;
	int	j;
	int	n;
	int len = 0;
	char	*way;

	i = 0;
	ref = 9999;
	while (rooms[i])
	{
		way = ft_strjoin_f(rooms[1][i], "\n", 1);
		n = simule_way(rooms, i, 1, way, len);
		if (n < ref)
		{
			ref = n;
			way = ft_strdup(way); // leaks, faire strdup_f
		}
		i++;
	}
	return (way);

}






int	main()
{
	char	***rooms;

	rooms = (char ***)malloc(sizeof(char **) * 6);
	rooms[0] = (char **)malloc(sizeof(char *) * 4);
	rooms[1] = (char **)malloc(sizeof(char *) * 4);
	rooms[2] = (char **)malloc(sizeof(char *) * 5);
	rooms[3] = (char **)malloc(sizeof(char *) * 5);
	rooms[4] = (char **)malloc(sizeof(char *) * 1);
	rooms[5] = NULL;

	//	rooms[0][0] = ft_strdup("0");
	//	rooms[0][1] = ft_strdup("1");
	//	rooms[0][2] = NULL;
	//	rooms[0][3] = NULL;

	rooms[0][0] = ft_strdup("0");
	rooms[0][1] = ft_strdup("2");
	rooms[0][2] = ft_strdup("3");
	rooms[0][3] = NULL;

	rooms[1][0] = ft_strdup("1");
	rooms[1][1] = ft_strdup("2");
	rooms[1][2] = ft_strdup("3");
	rooms[1][3] = NULL;

	rooms[2][0] = ft_strdup("2");
	rooms[2][1] = ft_strdup("0");
	rooms[2][2] = ft_strdup("1");
	rooms[2][3] = ft_strdup("3");
	rooms[2][4] = NULL;

	rooms[3][0] = ft_strdup("3");
	rooms[3][1] = ft_strdup("2");
	rooms[3][2] = ft_strdup("1");
	rooms[3][3] = ft_strdup("0");
	rooms[3][4] = NULL;

	rooms[4] = NULL;
	rooms[4][0] = NULL;


	char	*way;

	ft_putstr(way = run_algo(rooms));
	return (0);
}
