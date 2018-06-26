/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:07:26 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/21 11:01:54 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dest;
	int		i;
	int		j;

	i = (n > ft_strlen(s)) ? ft_strlen(s) : n;
	j = 0;
	if ((dest = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	while (j < i)
	{
		dest[j] = s[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
