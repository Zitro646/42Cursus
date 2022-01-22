/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:43:32 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:23:12 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_sa(t_list **list_a, int show)
{
	int		num_aux;

	if (*list_a != 0)
	{
		if ((*list_a)->next != 0)
		{
			num_aux = (*list_a)->content;
			(*list_a)->content = (*list_a)->next->content;
			(*list_a)->next->content = num_aux;
			if (show == 1)
				printf("sa\n");
		}
	}
}
