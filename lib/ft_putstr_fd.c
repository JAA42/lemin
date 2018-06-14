/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:49:40 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:49:41 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char *str;

	str = (char *)s;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
