#include "../inc/lem_in.h"

int			ft_motn(char *str)
{
	int		i;
	int		mot;

	i = 0;
	mot = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == '\n' && str[i] != '\n') || (str[i] != '\0' &&
			str[i + 1] == '\0'))
			mot++;
		i++;
	}
	return (mot);
}

int				ft_lettren(char *str)
{
	int			lettre;

	lettre = 0;
	while (*str != '\n' && *str != '\0' )
	{
		str++;
		lettre++;
	}
	return (lettre);
}

char			**ft_split_n(char *str)
{
	int			mot;
	char		**tab;
	int			i;
	int			j;

	mot = ft_motn(str);
	tab = (char**)malloc(sizeof(char*) * (mot + 1));
	i = 0;
	while (i < mot)
	{
		while (*str == '\n' && *str)
			str++;
		tab[i] = (char*)malloc(sizeof(char) * (ft_lettren(str) + 1));
		j = 0;
		while (*str != '\n' && *str != '\0')
		{
			tab[i][j++] = *str;
			str++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
