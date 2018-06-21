/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:58:27 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/21 14:43:57 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		add_branch_1(t_rooms *r1, char *str, int i, int ref)
{
	t_rooms *new_tube;

	while (r1->next_tube != NULL)
	{
		if (ft_strcmp(r1->name, str) == 0)
			return (0);
		r1 = r1->next_tube;
	}
	if (ft_strcmp(r1->name, str) == 0 ||
			!(new_tube = (t_rooms *)malloc(sizeof(t_rooms))))
		return (0);
	r1->next_tube = new_tube;
	new_tube->next_tube = NULL;
	new_tube->name = (ref != 1) ? ft_strndup(str, i) : ft_strdup(str + i + 1);
	return (1);
}

void	add_branch_2(t_rooms *r2, char *str, int i, int ref)
{
	t_rooms *new_tube;

	while (r2->next_tube != NULL)
	{
		if (ft_strcmp(r2->name, str) == 0)
			return ;
		r2 = r2->next_tube;
	}
	if (ft_strcmp(r2->name, str) == 0 ||
			!(new_tube = (t_rooms *)malloc(sizeof(t_rooms))))
		return ;
	r2->next_tube = new_tube;
	new_tube->next_tube = NULL;
	new_tube->name = (ref != 1) ? ft_strdup(str + i + 1) : ft_strndup(str, i);
	return ;
}

int		add_to_tubelist(w_pm *w, char *str, int i)
{
	t_rooms	*ptr;
	t_rooms	*tmp;

	int		n;
	int		ref;

	n = 0;
	ref = 0;
	ptr = w->first;
	while (ptr != NULL && n != 2)
	{
		if ((ft_strncmp(str, ptr->name, i) == 0) ||
			(ft_strcmp(str + i + 1, ptr->name) == 0 && (ref = 1)))
		{
			tmp = ptr;
			ptr = ptr->next_room;
			n++;
			while (ptr != NULL)
			{
				if ((ref == 1 ? ft_strncmp(str, ptr->name, i) == 0 :
					ft_strcmp(str + i + 1, ptr->name) == 0) && n++)
					break ;
				else
					ptr = ptr->next_room;
			}
		}
		else
			ptr = ptr->next_room;
	}
	if (n != 2)
		return (0);
	if (add_branch_1(ptr, str, i, ref))
		add_branch_2(tmp, str, i, ref);
	return (1);
}



void	get_tube_data(w_pm *w, char *str, int *n)
{
	int	i;

	i = 0;
	while (str[i] != '-')
		i++;
	printf("%s\n", str);
	if (!add_to_tubelist(w, str, i))
	{
		(*n)++;
		printf("MERDE\n");
	}
	else
	{
	
	}


}

void	create_room_tab(w_pm *w, int *i)
{
	(void)w;
	(void)i;
	// transforme liste chainee en ***
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
	cons_to_room(w, room_data, i);
	return (0);
}

void	get_input(w_pm *w)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (get_next_line(w->fd, &line) > 0)
	{
		if (is_comment(line))
			printf("%s\n", line);
		else if (i == 0 && (i = 1))
			get_ants_count(w, line);
		else if (i == 1)
			is_room_ok(w, line, &i);
		if (i == 2 && !is_comment(line))
			get_tube_data(w, line, &i);
		if (w->cmd != 1 || w->cmd != 2)
			free(line);
		if (i == 3)
			break ;
	}
	print_chained_list(w);
}
