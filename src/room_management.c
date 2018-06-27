/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:58:26 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/27 15:36:25 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"



static int		check_room_validity(t_pm *w, char *str)
{
	char	**room_data;
	int		i;
	int		k;

	k = 0;
	while (str[0] == '#')
	{
		free(str);
		get_next_line(w->fd, &str);
		k = is_cmd_tube(str);
		printf("%s\n", str);
		if (k == 1 || k == 2 || k == 3)
			ft_error(2);
	}
	room_data = ft_split(str);
	i = tablen(room_data);
	if (tablen(room_data) < 3 || !ft_onlydigit(room_data[i - 1])
			|| !ft_onlydigit(room_data[i - 2]) || is_cmd_tube(str) != 0)
	{
		printf("%s\n", str);
		ft_error(2);
	}
	else
		free_room_data(room_data);
	return (1);
}

static void	cons_to_room_list(t_pm *w, char **room_data, int i)
{
	t_rooms	*new;

	w->options_info[0] += 1;
	if (w->cmd == 1)
	{
		if (w->entrance)
			free(w->entrance);
		w->entrance = ft_cattab_str(room_data, i - 2);
	}
	else if (w->cmd == 2)
	{
		if (w->exit)
			free(w->exit);
		w->exit = ft_cattab_str(room_data, i - 2);
	}
	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		ft_error(0);
	new->name = ft_cattab_str(room_data, i - 2);
	new->weight = 0;
	new->next_room = NULL;
	new->next_tube = NULL;
	if (w->first)
	{
		w->last->next_room = new;
		w->last = new;
	}
	else
	{
		w->last = new;
		w->first = new;
	}
}

static void	manage_room_lst(t_pm *w, char *str)
{
	char	**room_data;
	int		i;

	room_data = ft_split(str);
	i = tablen(room_data);
	if (tablen(room_data) < 3 || !ft_onlydigit(room_data[i - 1])
			|| !ft_onlydigit(room_data[i - 2]))
		ft_error(2);
	cons_to_room_list(w, room_data, i);
	i = 0;
	while (room_data[i])
		free(room_data[i++]);
	free(room_data);
	free(str);
}

void		is_room_ok(t_pm *w, char *str, int *n)
{
	w->cmd = is_cmd_tube(str);
	if (w->cmd == 1 || w->cmd == 2)
	{
		printf("%s\n", str);
		free(str);
		get_next_line(w->fd, &str);
		if (!(check_room_validity(w, str)))
			return ;
	}
	else if (w->cmd == 3 && (*n)++)
	{
		if (w->entrance == NULL || w->exit == NULL)
			ft_error(3);
		return ;
	}
	else if (w->cmd == -1)
	{
		printf("%s\n", str);
		free(str);
		return ;
	}
	printf("%s\n", str);
	manage_room_lst(w, str);
	return ;
}
