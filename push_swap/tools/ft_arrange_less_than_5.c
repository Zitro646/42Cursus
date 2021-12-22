/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_less_than_5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:04:52 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/21 15:01:56 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
t_list	**ft_arrange_less_than_5(t_list **list_a, t_list **list_b)
{
	if (ft_list_is_sorted(*list_a) == 0)
	{
		while (ft_lstsize(*list_a) > 3)
		{
			if (ft_lstisnbrmin(*list_a, (*list_a)->content) == 1)
				ft_pb(list_a, list_b, 1);
			else if (ft_lstisnbrmin(*list_a, (*list_a)->next->content) == 1)
			{
				ft_sa(list_a, 1);
				ft_pb(list_a, list_b, 1);
			}
			else if (ft_lstisnbrmin(*list_a, ft_lstlast(*list_a)->content) == 1)
			{
				ft_rra(list_a, 1);
				ft_pb(list_a, list_b, 1);
			}
			else
				ft_ra(list_a, 1);
		}
		ft_arrange_less_than_3(list_a);
		while (ft_lstsize(*list_b) > 0)
		{
			//ft_look_arrays(*list_a, *list_b);
			ft_pa(list_a, list_b, 1);
		}
			
	}
	return (0);
}

/*
t_list	**ft_arrange_less_than_5(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) <= 3)
		return (list_a);
	while (ft_list_is_sorted(*list_a) == 0 || ft_lstsize(*list_b) != 0)
	{
		if ((*list_a)->content > ft_lstlast(*list_a)->content)
			ft_ra(list_a, 1);
		else if ((*list_a)->content > (*list_a)->next->content)
			ft_sa(list_a, 1);
		else if ((*list_a)->next->content > ft_lstlast(*list_a)->content)
			ft_sa(list_a, 1);
		else
		{
			if (ft_lstsize(*list_b) != 0 && ft_list_is_sorted(*list_a) == 1)
				ft_pa(list_a, list_b, 1);
			else
				ft_pb(list_a, list_b, 1);
		}
	}
	return (0);
}
*/
