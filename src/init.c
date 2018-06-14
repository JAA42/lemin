#include "../inc/lem_in.h"

t_pm	*init_struct(t_pm *s)
{
	if (!(s = (t_pm*)malloc(sizeof(t_pm))))
		return (NULL);
	s->nbants = 0;
	s->rooms = NULL;
	s->tubes = NULL;
	return (s);
}
