/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:50:13 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/25 16:06:52 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static int	add_branch_1(t_rooms *r1, t_rooms *r2, char *str, int *n)
{
	t_rooms *new_tube;

	while (r1->next_tube != NULL)
	{
		if (ft_strcmp(r1->name, str) == 0)
			return (0);
		r1 = r1->next_tube;
	}
	if (ft_strcmp(r1->name, str) == 0)
		return (0);
	else if (!(new_tube = (t_rooms *)malloc(sizeof(t_rooms))))
		ft_error(0);
	r1->next_tube = new_tube;
	new_tube->next_tube = NULL;
	new_tube->name = (n[1] != 1) ? ft_strndup(str, n[0]) :
		ft_strdup(str + n[0] + 1);
	new_tube->passage = r2;
	return (1);
}

static void	add_branch_2(t_rooms *r2, t_rooms *r1, char *str, int *n)
{
	t_rooms *new_tube;

	while (r2->next_tube != NULL)
	{
		if (ft_strcmp(r2->name, str) == 0)
			return ;
		r2 = r2->next_tube;
	}
	if (ft_strcmp(r2->name, str) == 0)
		return ;
	else if (!(new_tube = (t_rooms *)malloc(sizeof(t_rooms))))
		ft_error(0);
	r2->next_tube = new_tube;
	new_tube->next_tube = NULL;
	new_tube->name = (n[1] != 1) ? ft_strdup(str + n[0] + 1) :
		ft_strndup(str, n[0]);
	new_tube->passage = r1;
	return ;
}

static void	check_tube(char *str, t_rooms **ptr, int i, int *n)
{
	while ((*ptr) != NULL)
	{
		if ((n[1] == 1 ? ft_strncmp(str, (*ptr)->name, i) == 0 :
					ft_strcmp(str + i + 1, (*ptr)->name) == 0) && n[0]++)
			break ;
		else
			(*ptr) = (*ptr)->next_room;
	}
}

static int	add_to_tubelist(t_pm *w, char *str, int i)
{
	t_rooms	*ptr;
	t_rooms	*tmp;
	int		n[2];

	n[0] = 0;
	n[1] = 0;
	ptr = w->first;
	while (ptr != NULL && n[0] != 2)
		if ((ft_strncmp(str, ptr->name, i) == 0) ||
			(ft_strcmp(str + i + 1, ptr->name) == 0 && (n[1] = 1)))
		{
			tmp = ptr;
			ptr = ptr->next_room;
			n[0]++;
			check_tube(str, &ptr, i, n);
		}
		else
			ptr = ptr->next_room;
	if (n[0] != 2)
		return (0);
	n[0] = i;
	if (add_branch_1(ptr, tmp, str, n))
		add_branch_2(tmp, ptr, str, n);
	return (1);
}

void		get_tube_data(t_pm *w, char *str, int *n)
{
	int	i;

	i = 0;
	while (str[i] != '-')
		i++;
	printf("%s\n", str);
	if (!add_to_tubelist(w, str, i))
	{
		if (!w->first)
			ft_error(2);
		else
			ft_putstr_fd("\n\033[1;31m[ERROR: Bad tube data]\033[0m\n", 2);
		(*n)++;
	}
	free(str);
}
