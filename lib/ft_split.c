#include "../inc/lem_in.h"

int			ft_mot(char *str)
{
	int		i;
	int		mot;

	i = 0;
	mot = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == '\n' && str[i] != '\n' )
			mot++;
		i++;
	}
	return (mot);
}

int				ft_lettre(char *str)
{
	int			lettre;

	lettre = 0;
	while (*str != '\n')
	{
		str++;
		lettre++;
	}
	return (lettre);
}

char			**ft_split(char *str)
{
	int			mot;
	char		**tab;
	int			i;
	int			j;

	mot = ft_mot(str);
	tab = (char**)malloc(sizeof(char*) * (mot + 1));
	i = 0;
	while (i < mot)
	{
		while (*str == '\n')
			str++;
		tab[i] = (char*)malloc(sizeof(char) * (ft_lettre(str) + 1));
		j = 0;
		while (*str != '\n')
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
