/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_nbrpos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:31:18 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:12:23 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_get_nbrpos(t_list *lst, int nbr)
{
	int	cont;

	cont = 0;
	if (lst != 0)
	{
		while (lst->next != 0)
		{
			if (cont == nbr)
				return (lst->content);
			lst = lst->next;
			cont++;
		}
		return (-1);
	}
	return (-1);
}
