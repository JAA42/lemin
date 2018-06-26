/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:31:20 by avallois          #+#    #+#             */
/*   Updated: 2018/06/26 21:27:46 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

long	ft_long_atoi(const char *str)
{
	long i;
	long nb;
	long sign;

	nb = 0;
	sign = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	sign = (str[i] == '-') ? 1 : 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= 48) && (str[i] <= 57))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (sign == 1) ? -nb : nb;
}
