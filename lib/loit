/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:44:47 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/26 11:10:16 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char			*ft_uitoa(uintmax_t n)
{
	int			count;
	uintmax_t	j;
	char		*num;

	if (n == 9223372036854775807)
		return (ft_strdup("9223372036854775807"));
	count = 1;
	j = n;
	while (j /= 10)
		count++;
	if ((num = (char *)malloc(sizeof(char) * count + 1)) == NULL)
		return (NULL);
	num[count] = '\0';
	while (count-- >= 0)
	{
		num[count] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
