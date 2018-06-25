/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:16:20 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/25 14:53:38 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	sort_lst(t_way *lst_first)
{
	t_way	*ptr;
	char	*tmp;
	int		wtmp;

	ptr = lst_first;
	while (ptr->next)
	{
		if (ptr->weight > ptr->next->weight)
		{
			wtmp = ptr->weight;
			ptr->weight = ptr->next->weight;
			ptr->next->weight = wtmp;
			tmp = ptr->name;
			ptr->name = ptr->next->name;
			ptr->next->name = tmp;
			ptr = lst_first;
		}
		else
			ptr = ptr->next;
	}
}
