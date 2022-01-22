/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_less_than_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:15:38 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 16:44:32 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_list	**ft_arrange_less_than_3(t_list **list_a)
{
	if (ft_lstsize(*list_a) <= 1)
		return (list_a);
	while (ft_list_is_sorted(*list_a) == 0)
	{
		if ((*list_a)->content > ft_lstlast(*list_a)->content)
			ft_ra(list_a, 1);
		else if ((*list_a)->content > (*list_a)->next->content)
			ft_sa(list_a, 1);
		else if ((*list_a)->next->content > ft_lstlast(*list_a)->content)
			ft_sa(list_a, 1);
	}
	return (0);
}
