/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:07:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/20 11:26:01 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_look_arrays(t_list *list_a, t_list *list_b)
{
	while (list_a != 0 || list_b != 0)
	{
		if (list_a != 0)
		{
			printf("%i --- ", list_a->content);
			list_a = list_a->next;
		}
		else
			printf("  ---");
		if (list_b != 0)
		{
			printf(" %i\n", list_b->content);
			list_b = list_b->next;
		}
		else
			printf(" \n");
	}
	printf("_       _\na ----- b\n\n");
	return (0);
}
/*
int	ft_look_arrays(t_list **list_a, t_list **list_b)
{
	t_list	*aux_a;
	t_list	*aux_b;

	write(1,"esto es una prueba",18);
	aux_a = *list_a;
	aux_b = *list_b;
	while (aux_a != 0 || aux_b != 0)
	{
		if (aux_a != 0)
		{
			printf("%i --- ", aux_a->content);
			aux_a = aux_a->next;
		}
		else
			printf("  ---");
		if (aux_b != 0)
		{
			printf(" %i", aux_b->content);
			aux_b = aux_b->next;
		}
		else
			printf(" \n");
	}
	printf("_       _\na ----- b\n\n");
	return (0);
}
*/
//printf("primer valor %i\n", (*list_a)->content);
