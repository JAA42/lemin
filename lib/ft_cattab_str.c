/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cattab_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:22:07 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/19 16:29:06 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*ft_cattab_str(char **tab, int i)
{
	char	*ret;
	int		j;

	j = 0;
	ret = NULL;
	while (j < i)
	{
		if (!ret)
			ret = ft_strdup(tab[j]);
		else
			ret = ft_str3join_f(ret, " ", tab[j], 1);
		j++;
	}
	return (ret);
}
