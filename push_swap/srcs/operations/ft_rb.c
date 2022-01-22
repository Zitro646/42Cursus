/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:39:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:22:58 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rb(t_list **list_b, int show)
{
	t_list	*aux;

	if (*list_b != 0)
	{
		if ((*list_b)->next != 0)
		{
			aux = *list_b;
			*list_b = (*list_b)->next;
			(*list_b)->prev = 0;
			aux->next = 0;
			ft_lstadd_back(list_b, aux);
			if (show == 1)
				printf("rb\n");
		}
	}
}
