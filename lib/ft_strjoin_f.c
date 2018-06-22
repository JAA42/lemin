/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:52:11 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/22 20:34:23 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*ft_strjoin_f(char *s1, char *s2, int j)
{
	char	*dest;
	int		i;

	if (!(s1 && s2))
		return (NULL);
	i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if ((dest = (char *)malloc(sizeof(dest) * i + 1)) == NULL)
		return (NULL);
	dest = ft_strcpy(dest, s1);
	dest = ft_strcat(dest, s2);
	if (j == 1 || j == 3)
		free(s1);
	if (j == 2 || j == 3)
		free(s2);
	return (dest);
}
