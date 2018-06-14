#include "../inc/lem_in.h"

void	add_nb_ants(t_pm *s, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
		{
			free(line);
			ft_error();
		}
		i++;
	}
	if (s->nbants == 0)
		s->nbants = ft_atoi(line);
	else
		ft_error();
	ft_putstr(line);
}

void	get_datas(t_pm *s)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] != '#' && !ft_strchr(line, '-') && !ft_strchr(line, ' '))
			add_nb_ants(s, line);
		if (line[0] == '#' && line[1] != '#')
			ft_putstr(line);
		else
			ft_error();
		free(line);
	}
	//NE PAS OUBLIER DE FREE LINE A CHAQUE TOUR DU BAIL
}
