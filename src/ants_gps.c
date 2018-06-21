#include "../inc/lem_in.h"

void	cons_to_way_list(w_pm *w, char *name)
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

void	print_gps_data(w_pm *w)
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
		if (last->ant != 0 && last->ant <= 10)
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
	while (w->last_way->ant != 10)
		print_gps_data(w);
}
