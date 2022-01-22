/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisnbrmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:47:01 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:15:09 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstisnbrmax(t_list *lst, int nbr)
{
	int	aux;

	aux = nbr;
	if (lst != 0)
	{
		while (lst->next != 0)
		{
			if (lst->content > aux)
				return (0);
			lst = lst->next;
		}
		if (lst->content > aux)
			return (0);
		return (1);
	}
	return (0);
}
