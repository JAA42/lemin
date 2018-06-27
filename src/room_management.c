/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:58:26 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/27 21:10:00 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static char		*check_room_validity(t_pm *w, char *str)
{
	char	**room_data;
	int		i;
	int		k;

	k = 0;
	room_data = NULL;
	while (str[0] == '#')
	{
		ft_putstr(str);
		ft_putchar('\n');
		free(str);
		get_next_line(w->fd, &str);
		k = is_cmd_tube(str);
		if (k == 1 || k == 2 || k == 3)
			ft_error(2);
	}
	room_data = ft_split(str);
	i = tablen(room_data);
	if (tablen(room_data) < 3 || !ft_onlydigit(room_data[i - 1])
			|| !ft_onlydigit(room_data[i - 2]) || is_cmd_tube(str) != 0)
		display_room_error(str);
	else
		free_room_data(room_data);
	return (str);
}

void			init_room_struct(t_pm *w, t_rooms *new)
{
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
	init_room_struct(w, new);
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
		ft_putstr(str);
		ft_putchar('\n');
		free(str);
		get_next_line(w->fd, &str);
		str = check_room_validity(w, str);
	}
	else if (w->cmd == 3 && (*n)++)
	{
		display_start_end_error(w);
		return ;
	}
	else if (w->cmd == -1)
	{
		ft_putstr(str);
		ft_putchar('\n');
		free(str);
		return ;
	}
	ft_putstr(str);
	ft_putchar('\n');
	manage_room_lst(w, str);
	return ;
}
