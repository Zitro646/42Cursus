/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_nbrpos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:31:18 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/20 14:24:37 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
int	ft_lst_get_nbrpos(t_list *lst, int nbr)
{
	int	cont;

	cont = 0;
	if (lst != 0)
	{
		while (lst->next != 0)
		{
			//printf ("Numero visto : %i \n",lst->content);
			if (cont == nbr)
				return (lst->content);
			lst = lst->next;
			cont++;
		}
		return (-1);
	}
	return (-1);
}
