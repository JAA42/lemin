#include "../inc/lem_in.h"

static void	cons_to_way_list(w_pm *w, char *name)
{
	t_way	*new;

	if (!(new = (t_way *)malloc(sizeof(t_way))))
		return ;
	new->name = ft_strdup(name);
	new->ant = 0;
	new->next = NULL;
	new->previous = NULL;
	if (w->first_way)
	{
		new->previous = w->last_way;
		w->last_way->next = new;
		w->last_way = new;
	}
	else
	{
		w->last_way = new;
		w->first_way = new;
	}
}

static void	print_gps_data(w_pm *w)
{
	t_way	*last;
	t_way	*first;
	int		count;

	count = w->ants_count;
	last = w->last_way;
	first = w->first_way;
	while (first)
	{
		first->ant++;
		if (first->ant == 1)
			break;
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


void	split_way(w_pm *w)
{
	int		j;
	int		i;
	int		p;
	char	*name;

	j = ft_strlen(w->way);
	i = 0;
	p = 0;
	while (i <= j)
	{
		if (w->way[i] == '\n' || w->way[i] == '\0' )
		{
			name = ft_strsub(w->way, p, i - p);
			cons_to_way_list(w, name);
			free(name);
			p = i + 1;
		}
		i++;
	}
	while (w->last_way->ant != w->ants_count)
		print_gps_data(w);
}

void	get_ants_count(w_pm *w, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr("Error : Wrong ants number.\n"); // replace by ERROR
			exit (0);
		}
		i++;
	}
	printf("%d\n", ft_atoi(str));
	w->ants_count = ft_atoi(str);
}

