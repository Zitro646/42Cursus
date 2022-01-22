/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:36:19 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 18:09:55 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;
	t_list	*aux2;

	if (lst != 0)
	{
		aux = *lst;
		while (aux != 0)
		{
			aux2 = aux->next;
			aux->content = 0;
			if (aux->next == 0)
			{
				free (aux);
				break ;
			}
			free(aux);
			aux = aux2;
		}
		free(lst);
	}
}
