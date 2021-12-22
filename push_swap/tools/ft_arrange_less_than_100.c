/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_less_than_100.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:25:33 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/22 10:53:34 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
t_list	**ft_arrange_less_than_100(t_list **list_a, t_list **list_b)
{
	int	num;
	int	*chunks;
	int	chunkcount;
	int	chunktam;
	int	aux;

	ft_map_array(list_a);
	chunks = 0;
	num = -1;
	chunkcount = 0;
	while (ft_lstsize(*list_a) > 3)
	{
		chunkcount = 0;
		num += (ft_lstsize(*list_a) + ft_lstsize(*list_b)) / 4;
		if (num > ft_lstsize(*list_a) + ft_lstsize(*list_b))
		{
			num = (ft_lstsize(*list_a) + ft_lstsize(*list_b)) - 3;
		}
		while (ft_lstisnbrmin(*list_a, num) != 1)
		{
			if ((*list_a)->content < num)
			{
				ft_pb(list_a, list_b, 1);
				chunkcount++;
			}
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
			else if (ft_lstlast(*list_a)->content < num)
			{
				ft_rra(list_a, 1);
			}
			else
			{
				if (ft_lst_search_nbr(*list_a, num, 1) < ft_lst_search_nbr(*list_a, num, 3))
					ft_ra(list_a, 1);
				else
					ft_rra(list_a, 1);
			}
		}
		chunks = ft_manage_chunks(chunks, chunkcount, 1);
	}
	ft_arrange_less_than_3(list_a);
	//ft_look_arrays(*list_a, *list_b);
	//return (0);
	chunktam = 0;
	while (chunks[chunktam] != 0)
		chunktam++;
	num = (*list_a)->content - 1;
	while (ft_list_is_sorted(*list_a) && ft_lstsize(*list_b) > 0)
	{
		aux = 0;
		while (chunks[chunktam] + aux != 0)
		{
			if (ft_lstisnbrmax(*list_b, (*list_b)->content) == 1)
			{
				ft_pa(list_a, list_b, 1);
				num--;
				chunks[chunktam]--;
			}
			else if (ft_lstisnbrmax(*list_b, (*list_b)->next->content) == 1)
				ft_sb(list_b, 1);
			else if (ft_lstisnbrmax(*list_b, ft_lstlast(*list_b)->content) == 1)
			{
				ft_rrb(list_b, 1);
				chunks[chunktam]++;
				aux--;
			}
			else
			{
				if (ft_lst_search_nbr(*list_b, num, 2) < ft_lst_search_nbr(*list_b, num, 4))
				{
					ft_rb(list_b, 1);
					chunks[chunktam]--;
					aux++;
				}
				else
				{
					ft_rrb(list_b, 1);
					chunks[chunktam]++;
					aux--;
				}
			}
		}
		chunks = ft_manage_chunks(chunks, 0, 2);
		chunktam--;
	}
	//printf("List is sorted ? %i/1\n",ft_list_is_sorted(*list_a));
	free(chunks);
	return (0);
}

/* NO TIRA NADA BIEN
chunktam = 0;
	while (chunks[chunktam] != 0)
		chunktam++;
	num = (*list_a)->content - 1;
	while (ft_list_is_sorted(*list_a) && ft_lstsize(*list_b) > 0)
	{
		aux = 0;
		while (chunks[chunktam] + aux != 0)
		{
			if (ft_lstisnbrmax(*list_b, (*list_b)->content) == 1)
			{
				ft_pa(list_a, list_b, 1);
				num--;
				chunks[chunktam]--;
			}
			else if (ft_lstisnbrmax(*list_b, (*list_b)->next->content) == 1)
				ft_sb(list_b, 1);
			else if (ft_lstisnbrmax(*list_b, ft_lstlast(*list_b)->content) == 1)
			{
				ft_rrb(list_b, 1);
				chunks[chunktam]++;
				aux--;
			}
			else
			{
				printf("Obligado a moverse\n");
				printf("num : %i\n",num);
				printf("%i -- %i\n",ft_lst_search_nbr(*list_b, num, 2), ft_lst_search_nbr(*list_b, num, 4));
				if (ft_lst_search_nbr(*list_b, num, 2) < ft_lst_search_nbr(*list_b, num, 4))
				{
					ft_rb(list_a, 1);
					chunks[chunktam]--;
					aux++;
				}
				else
				{
					ft_rrb(list_a, 1);
					chunks[chunktam]++;
					aux--;
				}
				ft_rb(list_b, 1);
				chunks[chunktam]--;
				aux++;
				//return (0);
			}
		}
		chunks = ft_manage_chunks(chunks, 0, 2);
		chunktam--;
	}
*/