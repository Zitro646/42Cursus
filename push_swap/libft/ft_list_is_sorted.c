/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_is_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:22:44 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/27 09:51:04 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_list_is_sorted(t_list *list)
{
	t_list	*aux;

	aux = ft_lstlast(list);
	while (list != aux)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
