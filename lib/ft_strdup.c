/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:07:26 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/25 17:01:23 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		j;

	i = ft_strlen(s);
	j = 0;
	if (!s)
		return (NULL);
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
