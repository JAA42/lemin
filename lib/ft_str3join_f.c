/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:52:11 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/15 16:15:55 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*ft_str3join_f(char *s1, char *s2, char *s3, int i)
{
	char	*dest;

	dest = ft_strjoin(s1, s2);
	dest = ft_strjoin_f(dest, s3, 1);
	if (i == 1)
		free(s1);
	else if (i == 2)
		free(s2);
	else if (i == 3)
		free(s3);
	return (dest);
}
