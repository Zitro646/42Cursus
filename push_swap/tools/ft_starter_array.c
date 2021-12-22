/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starter_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:44:35 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/14 14:38:08 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
t_list	**ft_starter_array(t_list **list_a, char **argv, int list_size)
{
	int		i;	
	int		num;
	t_list	*aux;

	list_a = 0;
	i = 2;
	num = 0;
	if (list_size == 0)
		return (0);
	list_a = ft_calloc(sizeof(t_list), 2);
	*list_a = ft_lstnew(ft_atoi(argv[1]));
	while (i < list_size)
	{
		num = ft_atoi(argv[i]);
		aux = ft_lstnew(num);
		ft_lstadd_back(list_a, aux);
		i++;
	}
	return (list_a);
}

/*
t_list	*ft_starter_array(t_list *list_a, char **argv, int list_size)
{
	int		i;	
	int		num;
	t_list	*aux;

	list_a = 0;
	i = 2;
	num = 0;
	if (list_size == 0)
		return (0);
	list_a = ft_lstnew(ft_atoi(argv[1]));
	while (i < list_size)
	{
		num = ft_atoi(argv[i]);
		aux = ft_lstnew(num);
		ft_lstadd_back(&list_a, aux);
		i++;
	}
	return (list_a);
}
*/
