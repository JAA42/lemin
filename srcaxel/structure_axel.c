#include "../inc/lem_in.h"

void	init_w(w_pm **w)
{
	*w = (w_pm *)malloc(sizeof(w_pm));

	/*
	 * Exit devrat etre fournie par le parsing
	 * entrance devrat etre fournie par le parsing
	 * ***rooms devrat etre founir par le parsing
	 * ants_count doit etre fournie par le parsing
	 */
	(*w)->exit = ft_strdup("0"); 
	(*w)->entrance = ft_strdup("0"); 
	(*w)->len = -1;
	(*w)->ants_count = 4;
	
		/* SALLE 1 */
	
	(*w)->rooms = (char ***)malloc(sizeof(char **) * 6);
	(*w)->rooms[0] = (char **)malloc(sizeof(char *) * 4);
	(*w)->rooms[1] = (char **)malloc(sizeof(char *) * 4);
	(*w)->rooms[2] = (char **)malloc(sizeof(char *) * 5);
	(*w)->rooms[3] = (char **)malloc(sizeof(char *) * 5);
	(*w)->rooms[4] = (char **)malloc(sizeof(char *) * 1);
	(*w)->rooms[5] = NULL;

	(*w)->rooms[0][0] = ft_strdup("0");
	(*w)->rooms[0][1] = ft_strdup("2");
	(*w)->rooms[0][2] = ft_strdup("3");
	(*w)->rooms[0][3] = NULL;

	(*w)->rooms[1][0] = ft_strdup("1");
	(*w)->rooms[1][1] = ft_strdup("2");
	(*w)->rooms[1][2] = ft_strdup("3");
	(*w)->rooms[1][3] = NULL;

	(*w)->rooms[2][0] = ft_strdup("2");
	(*w)->rooms[2][1] = ft_strdup("0");
	(*w)->rooms[2][2] = ft_strdup("1");
	(*w)->rooms[2][3] = ft_strdup("3");
	(*w)->rooms[2][4] = NULL;

	(*w)->rooms[3][0] = ft_strdup("3");
	(*w)->rooms[3][1] = ft_strdup("2");
	(*w)->rooms[3][2] = ft_strdup("1");
	(*w)->rooms[3][3] = ft_strdup("0");
	(*w)->rooms[3][4] = NULL;

	(*w)->rooms[4] = NULL;

	/* SALLE 2 */
/*	(*w)->exit = ft_strdup("finish gang 0"); 
	(*w)->entrance = ft_strdup("1"); 

	(*w)->rooms = (char ***)malloc(sizeof(char **) * 9);
	int i = -1;
	while (++i < 8)
		(*w)->rooms[i] = (char **)malloc(sizeof(char *) * 6);
	(*w)->rooms[i] = NULL;

	(*w)->rooms[0][0] = ft_strdup("finish gang 0");
	(*w)->rooms[0][1] = ft_strdup("4");
	(*w)->rooms[0][2] = ft_strdup("6");
	(*w)->rooms[0][3] = NULL;//ft_strdup("");
	(*w)->rooms[0][4] = NULL; //ft_strdup("");
	(*w)->rooms[0][5] = NULL;

	(*w)->rooms[1][0] = ft_strdup("1");
	(*w)->rooms[1][1] = ft_strdup("salle 3");
	(*w)->rooms[1][2] = ft_strdup("2");
	(*w)->rooms[1][3] = NULL;//ft_strdup("");
	(*w)->rooms[1][4] = NULL; //ft_strdup("");
	(*w)->rooms[1][5] = NULL;

	(*w)->rooms[2][0] = ft_strdup("2");
	(*w)->rooms[2][1] = ft_strdup("5");
	(*w)->rooms[2][2] = ft_strdup("4");
	(*w)->rooms[2][3] = ft_strdup("1");
	(*w)->rooms[2][4] = ft_strdup("7");
	(*w)->rooms[2][5] = NULL;

	(*w)->rooms[3][0] = ft_strdup("salle 3");
	(*w)->rooms[3][1] = ft_strdup("1");
	(*w)->rooms[3][2] = ft_strdup("4");
	(*w)->rooms[3][3] = ft_strdup("5");
	(*w)->rooms[3][4] = NULL; //ft_strdup("");
	(*w)->rooms[3][5] = NULL;

	(*w)->rooms[4][0] = ft_strdup("4");
	(*w)->rooms[4][1] = ft_strdup("finish gang 0");
	(*w)->rooms[4][2] = ft_strdup("salle 3");
	(*w)->rooms[4][3] = ft_strdup("2");
	(*w)->rooms[4][4] = ft_strdup("7");
	(*w)->rooms[4][5] = NULL;

	(*w)->rooms[5][0] = ft_strdup("5");
	(*w)->rooms[5][1] = ft_strdup("2");
	(*w)->rooms[5][2] = ft_strdup("salle 3");
	(*w)->rooms[5][3] = ft_strdup("6");
	(*w)->rooms[5][4] = NULL; //ft_strdup("");
	(*w)->rooms[5][5] = NULL;

	(*w)->rooms[6][0] = ft_strdup("6");
	(*w)->rooms[6][1] = ft_strdup("finish gang 0");
	(*w)->rooms[6][2] = ft_strdup("7");
	(*w)->rooms[6][3] = ft_strdup("5");
	(*w)->rooms[6][4] = NULL; //ft_strdup("");
	(*w)->rooms[6][5] = NULL;

	(*w)->rooms[7][0] = ft_strdup("7");
	(*w)->rooms[7][1] = ft_strdup("6");
	(*w)->rooms[7][2] = ft_strdup("2");
	(*w)->rooms[7][3] = ft_strdup("4");
	(*w)->rooms[7][4] = NULL; //ft_strdup("");
	(*w)->rooms[7][5] = NULL;
*/}

