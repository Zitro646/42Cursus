/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:54:17 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/15 11:26:34 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
void	ft_rr(t_list **list_a, t_list **list_b, int show)
{
	if (*list_a != 0 && *list_b != 0)
	{
		if ((*list_a)->next != 0 && (*list_b)->next != 0)
		{
			ft_ra(list_a, 0);
			ft_rb(list_b, 0);
			if (show == 1)
				printf("rr\n");
		}
	}
}
