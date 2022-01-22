/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:14:23 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 15:15:55 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_how_many_numbers_below(t_list *lst, int num);

t_list	**ft_map_array(t_list **list)
{
	t_list	**aux;

	aux = ft_calloc(sizeof(t_list), 1);
	*aux = ft_lstmap(*list, *list, ft_how_many_numbers_below);
	ft_lstclear(list);
	return (aux);
}

int	ft_how_many_numbers_below(t_list *lst, int num)
{
	int	cont;

	cont = 0;
	if (lst != 0)
	{
		while (lst->next != 0)
		{
			if (lst->content < num)
				cont++;
			lst = lst->next;
		}
		if (lst->content < num)
			cont++;
		return (cont);
	}
	return (cont);
}
