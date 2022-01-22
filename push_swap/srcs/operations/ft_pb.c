/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:27:57 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 15:29:14 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_pb(t_list **list_a, t_list **list_b, int show)
{
	t_list	*aux;

	if (*list_b != 0)
	{
		aux = ft_lstnew((*list_a)->content);
		ft_lstadd_front(&(*list_b), aux);
	}
	else
	{
		aux = ft_lstnew((*list_a)->content);
		*list_b = aux;
	}
	aux = (*list_a)->next;
	ft_lstdelone(*list_a);
	*list_a = aux;
	if (list_a != 0)
		(*list_a)->prev = 0;
	if (show == 1)
		printf("pb\n");
}
