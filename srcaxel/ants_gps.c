#include "../inc/lem_in.h"

void	send_ants(w_pm *w, int checkpoint_sum, char **way)
{
	int	i;
	int	j;
	printf("\ntab0:%s| tab1:%s| tab2:%s|tab3:%s| \n", way[0], way[1], way[2], way[3]);
//	while (fourmis 1 n'est pas a end)
//	{
	// si i == 1 afficher une fois 
	// i == 2 afficher deux fois 
	//			si afficher 2 fois, 
	//				tant que (nbr de fois q qfficher > 0 & nbr de fois == 2)
	//					afficher Lx-yeme element de way
	//					x++; y--;
	//	i == 3 
	//		afficher 3 fourmis, nb de fois a aficher == 3 
	//			tant que (nbr de fois a afficher > 0)
	//				afficher Lx-yeme element de way 
	//				x++, y--;
	//etc....
//	}
//	while (//fourmis 1 à end, construire làlgo en sens inverse)
//	{
//		// algo dans le sens inverse 
//	}
	printf("\n");
	i = 0;
	while (i != checkpoint_sum)
	{
		j = 0;
		while (j <= i)
		{
			if (j != 0)
				printf(" ");
			printf("L%d-%s", j + 1, way[i - j]);
			j++;
		}
	printf("\n");
		i++;
	}
	i -= 1;
	while (--i >= 0)
	{
		j = 0;
		while (j <= i)
		{
			if (j != 0)
				printf(" ");
			printf("L%d-%s", checkpoint_sum - i + j, way[checkpoint_sum - 1 - j]);
			j++;
		}
	printf("\n");
	}

}