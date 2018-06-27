/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:28:25 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/27 20:26:18 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	update_journey(t_pm *w, char *str)
{
	if (w->cmd == 1)
		w->entrance = ft_strdup(str);
	else
		w->exit = ft_strdup(str);
}

int		is_comment_emptyline(char *str)
{
	if (str[0] == '#' && str[1] != '#')
		return (1);
	else if (str[0] == '\0')
		return (1);
	return (0);
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

void	ft_error(int error_number)
{
	if (error_number == 0)
		ft_putstr_fd("\n\033[1;31m[ERROR : Malloc failed\033[0m\n", 2);
	if (error_number == 1)
	{
		ft_putstr_fd("\n\033[1;31m[ERROR : Wrong ants Number ", 2);
		ft_putstr_fd("(> 0 && < 2.147.483.648)]\033[0m\n", 2);
	}
	else if (error_number == 2)
	{
		ft_putstr_fd("\n\033[1;31m[ERROR : Wrong room data", 2);
		ft_putstr_fd("/ Wrong Tube data]\033[0m\n", 2);
	}
	else if (error_number == 3)
		ft_putstr_fd("\n\033[1;31m[ERROR : No ##start / No ##end]\033[0m\n", 2);
	else if (error_number == 4)
		ft_putstr_fd("\n\033[1;31m[ERROR: No Way to ants freedom]\033[0m\n", 2);
	else if (error_number == 5)
		ft_putstr_fd("\n\033[1;32m[##Start = ##end]\033[0m\n", 2);
	exit(0);
}
