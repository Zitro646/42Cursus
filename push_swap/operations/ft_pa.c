/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:42:33 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/21 15:01:38 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
void	ft_pa(t_list **list_a, t_list **list_b, int show)
{
	t_list	*aux;

	if (*list_a != 0)
	{
		aux = ft_lstnew((*list_b)->content);
		ft_lstadd_front(&(*list_a), aux);
	}
	else
	{
		aux = ft_lstnew((*list_b)->content);
		*list_a = aux;
	}
	aux = (*list_b)->next;
	if (aux != 0)
		aux->prev = 0;
	ft_lstdelone(*list_b);
	*list_b = aux;
	if (show == 1)
		printf("pa\n");
}

/*
void	ft_pa(char **list_a, char **list_b)
{
	int		tam_a;
	int		tam_b;
	int		i;

	tam_a = ft_count_list(list_a);
	tam_b = ft_count_list(list_b);
	if (tam_b > 0)
	{
		while (tam_a >= 0)
		{
			list_a[tam_a + 1] = list_a[tam_a];
			tam_a--;
		}	
		list_a[0] = list_b[0];
		i = 0;
		while (i < tam_b)
		{
			list_b[i] = list_b[i + 1];
			i++;
		}
	}
}
*/