/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:07:45 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/21 13:57:54 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rra(t_list **list_a, int show)
{
	t_list	*aux;
	t_list	*aux2;

	if (*list_a != 0)
	{
		if ((*list_a)->next != 0)
		{
			aux = ft_lstlast(*list_a);
			aux2 = ft_lstlast(*list_a)->prev;
			aux2->next = 0;
			ft_lstadd_front(list_a, aux);
			(*list_a)->prev = 0;
			if (show == 1)
				printf("rra\n");
		}
	}
}
