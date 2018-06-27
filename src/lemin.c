/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:38:50 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/27 15:03:46 by adhondt          ###   ########.fr       */
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
		if (is_comment_emptyline(line))
		{

			printf("%s\n", line);
			free(line);
		}
		else if (i == 0 && (i = 1))
			get_ants_count(w, line);
		else if (i == 1)
			is_room_ok(w, line, &i);
		if (i == 2 && !is_comment_emptyline(line))
			get_tube_data(w, line, &i);
		if (i == 3)
			break ;
	}
	if (!w->entrance || !w->exit)
		ft_error(3);
}

void	display_options_infos(t_pm *w)
{
	if (isoption(w->options, 'r') || isoption(w->options, 'r') ||
			isoption(w->options, 'r'))
		printf("\n");
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
	static char *options_available = "Rrto";

	(void)argc;
	init_w(&w);
	w->options = get_options(argv, options_available);
	if (display_options(w))
		return (0);
	get_input(w);
	if (!run_algo(w))
		ft_error(5);
	send_ants_to_freedom(w);
	display_options_infos(w);
	free_rooms_list(w);
	free_way_list(w);
	free(w->entrance);
	free(w->exit);
	free(w->options);
	free(w);
	return (0);
}
