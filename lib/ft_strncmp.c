/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:17:36 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/19 10:41:46 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int	ft_strncmp(const char *tab, const char *teub, size_t n)
{
	size_t	i;
	int		nb;
	char	*s1;
	char	*s2;

	s1 = (char *)tab;
	s2 = (char *)teub;
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	nb = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (nb);
}
