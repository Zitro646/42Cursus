/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_less_than_5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:04:52 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 19:34:21 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	move_to_listb(t_list **list_a, t_list **list_b);

t_list	**ft_arrange_less_than_5(t_list **list_a, t_list **list_b)
{
	if (ft_list_is_sorted(*list_a) == 0)
	{
		move_to_listb(list_a, list_b);
		ft_arrange_less_than_3(list_a);
		while (ft_lstsize(*list_b) > 0)
			ft_pa(list_a, list_b, 1);
	}
	ft_lstclear(list_b);
	ft_lstclear(list_a);
	return (0);
}

static void	move_to_listb(t_list **list_a, t_list **list_b)
{	
	while (ft_lstsize(*list_a) > 3)
	{
		if (ft_lstisnbrmin(*list_a, (*list_a)->content) == 1)
			ft_pb(list_a, list_b, 1);
		else if (ft_lstisnbrmin(*list_a, (*list_a)->next->content) == 1)
		{
			if (ft_lstsize(*list_b) >= 2)
			{
				if ((*list_b)->next->content > (*list_b)->content)
					ft_ss(list_b, list_a, 1);
				else
					ft_sa(list_a, 1);
			}
			else
				ft_sa(list_a, 1);
		}
		else if (ft_lstisnbrmin(*list_a, ft_lstlast(*list_a)->content) == 1)
		{
			ft_rra(list_a, 1);
			ft_pb(list_a, list_b, 1);
		}
		else
			ft_ra(list_a, 1);
	}
}
