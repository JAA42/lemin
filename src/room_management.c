/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:58:26 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/22 12:34:49 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void	cons_to_room_list(w_pm *w, char **room_data, int i)
{
	t_rooms	*new;

	if (w->cmd == 1)
		w->entrance = ft_cattab_str(room_data, i - 2);
	else if (w->cmd == 2)
		w->exit = ft_cattab_str(room_data, i - 2);
	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		return ;
	new->name = ft_cattab_str(room_data, i - 2);
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

int		is_room_ok(w_pm *w, char *str, int *n)
{
	int	i;
	char	**room_data;
	
	w->cmd = is_cmd_tube(str);
	if (w->cmd == 1 || w->cmd == 2)
	{
		printf("%s\n", str);
		free(str);
		get_next_line(w->fd, &str);
	}
	else if (w->cmd == 3)
	{
		(*n)++;
		return (0);
	}
	else if (w->cmd == -1)
	{
		printf("%s\n", str);
		return (0);
	}
	printf("%s\n", str);
	room_data = ft_split(str);
	i = tablen(room_data);
	if (tablen(room_data) < 3 || !ft_onlydigit(room_data[i - 1])
			|| !ft_onlydigit(room_data[i - 2]))
	{
		ft_putstr("ERROR : room not ok\n");
		exit (0);
	}
	cons_to_room_list(w, room_data, i);
	return (0);
}
