#include "../inc/lem_in.h"

void			display_passage(int ant, char *name)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("->");
	ft_putstr(name);
	ft_putstr(" ");
}

void			display_room_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	ft_error(2);
}

void		display_start_end_error(t_pm *w)
{
	if (w->entrance == NULL || w->exit == NULL)
		ft_error(3);
}
