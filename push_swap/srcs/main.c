/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:36:20 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 19:03:01 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	final_free(t_list **lst_a, t_list **lst_b)
{
	ft_lstclear(lst_a);
	ft_lstclear(lst_b);
}

int	error_control(int argc, char **argv, t_list **list_a, t_list **list_b)
{
	if (ft_error_checker(argv, argc) == 0)
	{
		final_free(list_a, list_b);
		if (argc != 1)
			printf("Error\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	**list_a;
	t_list	**list_b;
	int		tam;

	list_b = ft_calloc(sizeof(t_list), 1);
	list_a = ft_starter_array(0, argv, argc);
	if (error_control(argc, argv, list_a, list_b) == 0)
		return (0);
	tam = ft_lstsize(*list_a);
	if (tam <= 3 && tam > 0)
	{
		ft_arrange_less_than_3(list_a);
		final_free(list_a, list_b);
	}
	else if (tam <= 5 && tam > 0)
		ft_arrange_less_than_5(list_a, list_b);
	else if (tam <= 19 && tam > 0)
		ft_arrange_more_than_5(list_a, list_b, 2);
	else if (tam <= 100 && tam > 0)
		ft_arrange_more_than_5(list_a, list_b, 4);
	else
		ft_arrange_more_than_5(list_a, list_b, 11);
	return (1);
}
