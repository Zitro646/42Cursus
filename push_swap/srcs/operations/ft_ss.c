/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:34:34 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:23:18 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_ss(t_list **list_a, t_list **list_b, int show)
{
	if (*list_a != 0 && *list_b != 0)
	{
		if ((*list_a)->next != 0 && (*list_b)->next != 0)
		{
			ft_sa(list_a, 0);
			ft_sb(list_b, 0);
			if (show == 1)
				printf("ss\n");
		}
	}
}
