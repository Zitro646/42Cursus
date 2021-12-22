/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:14:23 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/20 09:58:42 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
int	ft_how_many_numbers_below(t_list *lst, int num);

void	ft_map_array(t_list **list)
{
	t_list	*aux;

	aux = ft_lstmap(*list, *list, ft_how_many_numbers_below);
	ft_lstclear(list);
	*list = aux;
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
