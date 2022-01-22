/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:32:56 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:23:15 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_sb(t_list **list_b, int show)
{
	int		num_aux;

	if (*list_b != 0)
	{
		if ((*list_b)->next != 0)
		{
			num_aux = (*list_b)->content;
			(*list_b)->content = (*list_b)->next->content;
			(*list_b)->next->content = num_aux;
			if (show == 1)
				printf("sb\n");
		}
	}
}
