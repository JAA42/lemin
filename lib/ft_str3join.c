/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:52:11 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/14 20:00:43 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*ft_str3join(char const *s1, char const *s2, char *s3)
{
	char	*dest;

	dest = ft_strjoin(s1, s2);
	dest = ft_strjoin_f(dest, s3, 1);
	return (dest);
}
