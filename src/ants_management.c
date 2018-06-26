/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:55:35 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/26 19:59:33 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		sort_lst(t_way *lst_first)
{
	t_way	*ptr;
	char	*tmp;
	int		wtmp;

	ptr = lst_first;
	while (ptr->next)
	{
		if (ptr->weight > ptr->next->weight)
		{
			wtmp = ptr->weight;
			ptr->weight = ptr->next->weight;
			ptr->next->weight = wtmp;
			tmp = ptr->name;
			ptr->name = ptr->next->name;
			ptr->next->name = tmp;
			ptr = lst_first;
		}
		else
			ptr = ptr->next;
	}
}
static void		print_gps_data(t_pm *w, t_way *first_gps, t_way *last_gps)
{
	t_way	*last;
	t_way	*first;
	int		count;

	count = w->ants_count;
	last = last_gps;
	first = first_gps;
	while (first)
	{
		first->ant++;
		if (first->ant == 1)
			break ;
		first = first->next;
	}
	while (last)
	{
		if (last->ant != 0 && last->ant <= w->ants_count)
			printf("L%d->%s ", last->ant, last->name);
		last = last->previous;
	}
	printf("\n");
}

static t_way	*add_gps_data(char *name, int weight, t_way **gps_data)
{
	t_way		*new;

	if ((*gps_data)->name == NULL)
	{
		(*gps_data)->name = ft_strdup(name);
		(*gps_data)->weight = weight;
		(*gps_data)->ant = 0;
		(*gps_data)->next = NULL;
		(*gps_data)->previous = NULL;
		return (*gps_data);
	}
	if (!(new = (t_way *)malloc(sizeof(t_way))))
		ft_error(0);
	(*gps_data)->next = new;
	new->next = NULL;
	new->name = ft_strdup(name);
	new->ant = 0;
	new->weight = weight;
	new->previous = (*gps_data);
	return (new);
}

void			send_ants_to_freedom(t_pm *w)
{
	t_rooms	*ptr;
	t_way	*gps_data;
	t_way	*first_gps;
	t_way	*tmp;
	t_way	*tmp2;

	ptr = w->first;
	if (!(gps_data = (t_way *)malloc(sizeof(t_way))))
		ft_error(0);
	gps_data->name = NULL;
	first_gps = gps_data;
	while (ptr)
	{
		if (ptr->weight > 0)
			gps_data = add_gps_data(ptr->name, ptr->weight, &gps_data);
		ptr = ptr->next_room;
	}
	sort_lst(first_gps);
	printf("\n");
	while (gps_data->ant != w->ants_count)
		print_gps_data(w, first_gps, gps_data);
	tmp = first_gps;
	while (tmp)
	{
		free(tmp->name);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void			get_ants_count(t_pm *w, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error(1);
		i++;
	}
	printf("%s\n", str);
	w->ants_count = ft_atoi(str);
	if (w->ants_count <= 0)
		ft_error(1);
	free(str);
}
