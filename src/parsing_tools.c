/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:28:25 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/21 14:46:30 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	update_journey(w_pm *w, char *str)
{
	if (w->cmd == 1)
		w->entrance = ft_strdup(str);
	else
		w->exit = ft_strdup(str);
}

int		is_comment(char *str)
{
	return (str[0] == '#' && str[1] != '#');
}

void	get_ants_count(w_pm *w, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr("Error : Wrong ants number.\n"); // replace by ERROR
			exit (0);
		}
		i++;
	}
	printf("%d\n", ft_atoi(str));
	w->ants_count = ft_atoi(str);
}

int		is_cmd_tube(char *line)
{
	if (ft_strncmp(line, "##", 2) != 0)
	{
		if (pos_in_str('-', line) >= 0)
			return (3);
		return (0);
	}
	else if (ft_strcmp(line, "##start") == 0)
		return (1);
	else if (ft_strcmp(line, "##end") == 0)
		return (2);
	else
		return (-1);
}

void	print_chained_list(w_pm *w)
{
	t_rooms	*ptr;
	t_rooms	*tube_ptr;
	int		i;

	ptr = w->first;
	i = 0;
	while (ptr != NULL)
	{
		printf("Maillon %d:%s|\n", i++, ptr->name);
		tube_ptr = ptr->next_tube;
		while (tube_ptr)
		{
			printf("\tTube : %s|\n", tube_ptr->name);
			tube_ptr = tube_ptr->next_tube;
		}
		ptr = ptr->next_room;
	}
}

void	cons_to_room(w_pm *w, char **room_data, int i)
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