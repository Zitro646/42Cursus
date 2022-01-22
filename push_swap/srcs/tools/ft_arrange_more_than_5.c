/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_more_than_5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:25:33 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 18:18:58 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	move_numbers_lista(t_list **list_a, t_list **list_b, int num);
static void	move_numbers_listb(t_list **list_a, t_list **list_b, int num);

t_list	**ft_arrange_more_than_5(t_list **list_a, t_list **list_b, int div)
{
	int	num;

	list_a = ft_map_array(list_a);
	num = -1;
	if (ft_list_is_sorted(*list_a) != 1)
	{
		while (ft_lstsize(*list_a) > 1)
		{
		num += (ft_lstsize(*list_a) + ft_lstsize(*list_b)) / div;
			if (num > ft_lstsize(*list_a) + ft_lstsize(*list_b))
				num = (ft_lstsize(*list_a) + ft_lstsize(*list_b)) - 1;
			move_numbers_listb(list_a, list_b, num);
		}
		num = (*list_a)->content - 1;
		move_numbers_lista(list_a, list_b, num);
	}
	ft_lstclear(list_a);
	free(list_b);
	return (0);
}

static void	move_numbers_listb(t_list **list_a, t_list **list_b, int num)
{	
	while (ft_lstisnbrmin(*list_a, num) != 1 && ft_lstsize(*list_a) > 1)
	{
		if ((*list_a)->content < num)
			ft_pb(list_a, list_b, 1);
		else if ((*list_a)->next->content < num)
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
		else
		{
			if (ft_lst_search_nbr(*list_a, num, 1) < \
				ft_lst_search_nbr(*list_a, num, 3))
				ft_ra(list_a, 1);
			else
				ft_rra(list_a, 1);
		}
	}
}

static void	move_numbers_lista(t_list **list_a, t_list **list_b, int num)
{
	while (ft_list_is_sorted(*list_a) && ft_lstsize(*list_b) > 0)
	{
		if (ft_lstisnbrmax(*list_b, (*list_b)->content) == 1)
		{
			ft_pa(list_a, list_b, 1);
			num--;
		}
		else if (ft_lstisnbrmax(*list_b, (*list_b)->next->content) == 1)
			ft_sb(list_b, 1);
		else if (ft_lstisnbrmax(*list_b, ft_lstlast(*list_b)->content) == 1)
			ft_rrb(list_b, 1);
		else
		{
			if (ft_lst_search_nbr(*list_b, num, 2) < \
				ft_lst_search_nbr(*list_b, num, 4))
				ft_rb(list_b, 1);
			else
				ft_rrb(list_b, 1);
		}
	}
}
