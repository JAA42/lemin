/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:50:13 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/23 18:53:28 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static int		add_branch_1(t_rooms *r1, char *str, int i, int ref)
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
	new_tube->done = 0;
	new_tube->next_tube = NULL;
	new_tube->name = (ref != 1) ? ft_strndup(str, i) : ft_strdup(str + i + 1);
	return (1);
}

static void	add_branch_2(t_rooms *r2, char *str, int i, int ref)
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
	new_tube->done = 0;
	new_tube->next_tube = NULL;
	new_tube->name = (ref != 1) ? ft_strdup(str + i + 1) : ft_strndup(str, i);
	return ;
}

static int		add_to_tubelist(t_pm *w, char *str, int i)
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

void	get_tube_data(t_pm *w, char *str, int *n)
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
