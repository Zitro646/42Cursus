/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:36:20 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/27 12:29:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**list_a;
	t_list	**list_b;

	list_b = ft_calloc(sizeof(t_list), 2);
	list_a = ft_starter_array(0, argv, argc);
	if (ft_error_checker(argv, argc) == 0)
	{
		ft_lstclear(list_a);
		ft_lstclear(list_b);
		printf("Error\n");
		return (0);
	}
	if ((argc - 1) <= 3)
		ft_arrange_less_than_3(list_a);
	else if ((argc - 1) <= 5)
		ft_arrange_less_than_5(list_a, list_b);
	else if ((argc - 1) <= 19)
		ft_arrange_more_than_5(list_a, list_b, 2);
	else if ((argc - 1) <= 100)
		ft_arrange_more_than_5(list_a, list_b, 4);
	else
		ft_arrange_more_than_5(list_a, list_b, 11);
	return (1);
}
