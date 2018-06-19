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
	ft_putchar('\n');
}

void	get_rooms_data(w_pm *w, char *str, int *i, int cmd)
{
	if (cmd == -1)
		return ;
	else if (cmd == 1 || cmd == 2)
		ft_update_journey(w, cmd, str);
	else if (is_room(str))
		add_to_roomlist(w, str);
	else if (is_tube(str))
		*i = 2;
	else
		//ERROR exit(0)
	// si cest start ou end 
	// si cest un tube -> passer en etat tube et integrer ce tube
	// si cest une salle, verifier quelle est bonne et la save
	//
	//
	// faire une liste chainee par room, putstr les data 
	// si une est un tube ou pas une room EXIT ERROR 
	// si tube *i += 1;
}

void	get_tube_data(w_pm *w, char *str, int *i)
{
	if (is_tube)
		add_to_tubelist
	else if (!is_tube_existing_tube)
		*i = 3;
		//error exit(0);
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

int		is_cmd(char *line)
{
	if (ft_strncmp(line, "##", 2) != 0)
		return (0);
	if (ft_strcmp(line, "##start") == 0)
		return (1);
	else if (ft_strcmp(line, "##end") == 0)
		return (2);
	return (-1);
}

void	get_input(w_pm *w)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (is_comment(line))
			;
		else if (i == 0 && (i = 1))
			get_ants_count(w, line);
		else if (i == 1)
			get_rooms_data(w, line, &i, is_cmd(line));
		if (i == 2)
			get_tube_data(w, line, &i);
		free(line);
		if (i == 3)
			break ;
	}
}
