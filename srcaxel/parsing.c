#include "../inc/lem_in.h"

void	get_ants_count(w_pm *w, char *str)
{
	int	i;

	i = 0;
	while (str[i])
 	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr("Error : Wrong ants number.\n"); // replace with ERROR
			exit (0);
		}
	}
	w->ants_count = ft_atoi(str);
	ft_putstr(str);
}

void	get_rooms_data(w_pm *w, char *str, int *i)
{
	// faire une liste chainee par room, putstr les data 
	// si une est un tube ou pas une room EXIT ERROR 
	// si tube *i += 1;
}

void	get_tube_data(w_pm *w, char *str)
{
	// register a chaque fois quil croise une room pour pouvoir malloc le 
	// bon nombre de ** a la fin de la lecture
}

void	create_room_tab(w_pm *w, int *i)
{
	// transforme liste chainee en ***
}

int		is_comment(char *str)
{
	return (str[0] == '#' && str[1] != '#');
}

void	get_input(w_pm *w)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (is_comment(line))
			;
		else if (i == 0 && (i = 1))
			get_ants_count(w, line);
		else if (i == 1)
			get_rooms_data(w, line, &i, is_cmd(/*verifier si ##*/));
		else if (i == 2)
			create_room_tab(w, &i);
		else if (i == 3)
			get_tube_data(w, line);
		free(line);
	}

}
