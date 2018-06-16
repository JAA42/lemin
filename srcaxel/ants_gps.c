#include "../inc/lem_in.h"

void	send_last_ants(char **way, int i, int checkpoint_sum)
{
	int	j;
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

void	send_ants(w_pm *w, int checkpoint_sum, char **way)
{
	int	i;
	int	j;
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
	send_last_ants(way, i, checkpoint_sum);
}
