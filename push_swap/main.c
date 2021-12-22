/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:36:20 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/22 13:59:44 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "operations/operations.h"
#include "tools/tools.h"

int	ft_look_reverse(t_list *list);

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
		printf("Error");
		return (0);
	}
	//printf("Problemas?\n");
	
	
	if ((argc - 1) <= 3)
		ft_arrange_less_than_3(list_a);
	else if ((argc - 1) <= 5)
		ft_arrange_less_than_5(list_a, list_b);
	else if ((argc - 1) <= 100)
		ft_arrange_less_than_100(list_a, list_b);
	else
		ft_arrange_more_than_100(list_a, list_b);	

	//printf("Hay %i posiciones de diferencia entre 2 y 1 mirando hacia abajo\n", ft_lst_search_nbr(*list_b, 98, 2));
	//printf("Hay %i posiciones de diferencia entre 2 y 1 mirando hacia arriba\n", ft_lst_search_nbr(*list_b, 1, 4));
	//ft_look_arrays(*list_a, *list_b);
	
	return (1);
}

int	ft_look_reverse(t_list *list)
{
	while (list != 0)
	{
		if (list->prev != 0)
			printf(" %i --> ",list->prev->content);
		else
			printf("    --> ");
		printf("%i --> ",list->content);
		if (list->next != 0)
			printf("%i\n",list->next->content);
		else
			printf("  \n");
		list = list->next;
	}
	return (0);
}

/*
	if ((argc - 1) <= 3)
		ft_arrange_less_than_3(list_a);
	else if ((argc - 1) <= 5)
		ft_arrange_less_than_5(list_a, list_b);
	else if ((argc - 1) <= 100)
		ft_arrange_less_than_100(list_a, list_b);
	else
		ft_arrange_more_than_100(list_a,list_b);
	//printf("FIN");
	//system("leaks -q a.out");
	//ft_look_arrays(*list_a, *list_b);
	*/

/*
	printf("TESTEO DE LA HERRAMIENTA : ");
	ft_ss(list_a, list_b, 1);
	ft_look_arrays(*list_a, *list_b);

*/

//sprintf("Hay %i posiciones de diferencia entre 7 y 1\n", ft_lst_search_up_dst(*list_a, 7));
	//printf("Hay %i posiciones de diferencia entre 7 y 1\n", ft_lst_search_down_dst(*list_a, 7));
	//ft_look_arrays(*list_a, *list_b);