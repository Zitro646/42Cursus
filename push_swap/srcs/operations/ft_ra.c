/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:33:24 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:22:55 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_ra(t_list **list_a, int show)
{
	t_list	*aux;

	if (*list_a != 0)
	{
		if ((*list_a)->next != 0)
		{
			aux = *list_a;
			*list_a = (*list_a)->next;
			(*list_a)->prev = 0;
			aux->next = 0;
			ft_lstadd_back(list_a, aux);
			if (show == 1)
				printf("ra\n");
		}
	}
}
