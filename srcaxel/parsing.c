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

}

void	get_tube_data(w_pm *w, char *str)
{

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
			get_rooms_data(w, line, &i);
		else if (i == 2)
			get_tube_data(w, line);
	}

}
