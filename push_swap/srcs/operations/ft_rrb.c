/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:55 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:23:07 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rrb(t_list **list_b, int show)
{
	t_list	*aux;
	t_list	*aux2;

	if (*list_b != 0)
	{
		if ((*list_b)->next != 0)
		{
			aux = ft_lstlast(*list_b);
			aux2 = ft_lstlast(*list_b)->prev;
			aux2->next = 0;
			ft_lstadd_front(list_b, aux);
			(*list_b)->prev = 0;
			if (show == 1)
				printf("rrb\n");
		}
	}
}
