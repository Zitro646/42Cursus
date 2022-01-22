/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:35 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:23:09 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rrr(t_list **list_a, t_list **list_b, int show)
{
	if (*list_a != 0 && *list_b != 0)
	{
		if ((*list_a)->next != 0 && (*list_b)->next != 0)
		{
			ft_rra(list_a, 0);
			ft_rrb(list_b, 0);
			if (show == 1)
				printf("rrr\n");
		}
	}
}
