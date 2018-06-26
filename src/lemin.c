/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:38:50 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/26 17:16:01 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void	init_w(t_pm **w)
{
	int	i;

	i = 0;
	if (!(*w = (t_pm *)malloc(sizeof(t_pm))))
		ft_error(0);
	(*w)->fd = 0;
	(*w)->first = NULL;
	(*w)->last = NULL;
	(*w)->first_way = NULL;
	(*w)->last_way = NULL;
	(*w)->options = NULL;
	(*w)->exit = NULL;
	(*w)->entrance = NULL;
	(*w)->len = -1;
	(*w)->way = NULL;
	(*w)->ants_count = 0;
	while (i < 3)
		(*w)->options_info[i++] = 0;
}

static void	get_input(t_pm *w)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (get_next_line(w->fd, &line) > 0)
	{
		if (is_comment(line))
		{
			printf("%s\n", line);
			free(line);
		}
		else if (i == 0 && (i = 1))
			get_ants_count(w, line);
		else if (i == 1)
			is_room_ok(w, line, &i);
		if (i == 2 && !is_comment(line))
			get_tube_data(w, line, &i);
		if (i == 3)
			break ;
	}
	if (!w->entrance || !w->exit)
		ft_error(3);
}

void		free_rooms_list(t_pm *w)
{
	t_rooms *ptr;
	t_rooms *tmp;
	t_rooms *ptr2;
	t_rooms *tmp2;

	ptr = w->first;
	while (ptr)
	{
		ptr2 = ptr->next_tube;
		while (ptr2)
		{
			free(ptr2->name);
			tmp2 = ptr2->next_tube;
			free(ptr2);
			ptr2 = tmp2;
		}
		free(ptr->name);
		tmp = ptr->next_room;
		free(ptr);
		ptr = tmp;
	}
}

void		free_way_list(t_pm *w)
{
	t_way *ptr;
	t_way *tmp;

	ptr = w->first_way;
	while (ptr)
	{
		free(ptr->name);
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

void	display_options_infos(t_pm *w)
{
	if (isoption(w->options, 'r'))
		printf("Number of rooms --> %d\n", w->options_info[0]);
	if (isoption(w->options, 't'))
		printf("Number of tubes --> %d\n", w->options_info[1]);
	if (isoption(w->options, 'R'))
		printf("Rooms tried --> %d\n", w->options_info[2]);
}

int		display_options(t_pm *w)
{
	if (isoption(w->options, 'o'))
	{
		printf("r : Number of rooms\n");
		printf("t : Number of tubes\n");
		printf("R : Number of rooms tried\n");
		free(w->options);
		free(w);
		return (1);
	}
	return (0);
}

int			main(int argc, char *argv[])
{
	t_pm	*w;
	static char *options_available = "Rrto"; //manque le f pour fast eventuellement

	(void)argc;
	init_w(&w);
	w->options = get_options(argv, options_available);
	if (display_options(w))
		return (0);
	get_input(w);
//	printf("opt2:%d|\n", w->options_info[0]);
	if (!run_algo(w))
		ft_error(5);
	send_ants_to_freedom(w);
	display_options_infos(w);
	free_rooms_list(w);
	free_way_list(w);
	free(w->way);
	free(w->entrance);
	free(w->exit);
	free(w);
	return (0);
}
