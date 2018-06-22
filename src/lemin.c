/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:38:50 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/22 12:29:49 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"


static void	init_w(w_pm **w)
{
	if (!(*w = (w_pm *)malloc(sizeof(w_pm))))
		return ;

	(*w)->options = ft_strdup("....");
	(*w)->fd = 0;
	(*w)->first = NULL;
	(*w)->last = NULL;
	(*w)->first_way = NULL;
	(*w)->last_way = NULL;
	(*w)->exit = NULL;
	(*w)->entrance = NULL;
	(*w)->len = -1;
	(*w)->ants_count = 0;
}
static void	get_input(w_pm *w)
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
//	print_chained_list(w);
}

int	main()
{
	w_pm	*w;

	init_w(&w);
	get_input(w);
	if (!run_algo(w))
	{
		 ft_putstr("No way\n");
		exit(0);
	}
	split_way(w);
	return (0);
}
