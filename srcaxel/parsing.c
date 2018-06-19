#include "../inc/lem_in.h"





int		add_to_tubelist(w_pm *w, char *str)
{
	t_rooms	*ptr;

	ptr = w->first;
	while (ptr->next_room != NULL)
	{
	
	}
	return (1);
}



void	get_tube_data(w_pm *w, char *str, int *n)
{
	int	i;

	i = 0;
	while (str[i] != '-')
		i++;
	// use ft_strncmp pour comparer avec chaque eleme de la liste
	if (!add_to_tubelist(w, str))
	{
		(*n)++;
		printf("\n");
	}

}

void	create_room_tab(w_pm *w, int *i)
{
	// transforme liste chainee en ***
}

int		is_room_ok(w_pm *w, char *str, int *n)
{
	int	i;
	char	**room_data;
	
	w->cmd = is_cmd_tube(str);
	if (w->cmd == 1 || w->cmd == 2)
	{
		printf("%s\n", str);
		free(str);
		get_next_line(w->fd, &str);
	}
	else if (w->cmd == 3)
	{
		printf("%s\n", str);
		(*n)++;
		return (0);
	}
	else if (w->cmd == -1)
	{
		printf("%s\n", str);
		return (0);
	}
	printf("%s\n", str);
	room_data = ft_split(str);
	i = tablen(room_data);
	if (tablen(room_data) < 3 || !ft_onlydigit(room_data[i - 1])
			|| !ft_onlydigit(room_data[i - 2]))
	{
		ft_putstr("ERROR : room not ok\n");
		exit (0);
	}
	cons_to_room(w, room_data, i);
	//free le tableau room data
	return (0);
}

void	get_input(w_pm *w)
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
	.	if (w->cmd != 1 || w->cmd != 2)
			free(line);
		if (i == 3)
			break ;
	}
	//print_chained_list(w);
}
