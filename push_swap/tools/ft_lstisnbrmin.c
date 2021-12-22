/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisnbrmin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:00:42 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/16 14:25:11 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
int	ft_lstisnbrmin(t_list *lst, int nbr)
{
	int	aux;

	aux = nbr;
	if (lst != 0)
	{
		while (lst->next != 0)
		{
			if (lst->content < aux)
				return (0);
			lst = lst->next;
		}
		if (lst->content < aux)
			return (0);
		return (1);
	}
	return (0);
}
