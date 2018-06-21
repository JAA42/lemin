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

void	print_gps_data()
{
	

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
	print_gps_data(w);
/*
	t_way	*ptr;

	ptr = w->first_way;
	while (ptr)
	{
		printf("--%s, end:%s\n", ptr->name, w->exit);
		ptr = ptr->next;
	}
	ptr = w->last_way;
	while (ptr)
	{
		printf("##%s|\n", ptr->name);
		ptr = ptr->previous;
	}
*/}
