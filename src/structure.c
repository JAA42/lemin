#include "../inc/lem_in.h"

void	init_w(w_pm **w)
{
	if (!(*w = (w_pm *)malloc(sizeof(w_pm))))
		return ;

	(*w)->options = ft_strdup("....");
	(*w)->fd = 0;
	(*w)->first = NULL;
	(*w)->last = NULL;
	(*w)->first_way = NULL;
	(*w)->last_way = NULL;
	(*w)->exit = ft_strdup("0"); 
	(*w)->entrance = ft_strdup("3"); 
	(*w)->len = -1;
	(*w)->ants_count = 0;
}

