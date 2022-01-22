/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_search_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:14:48 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 09:12:38 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lst_search_down_aprox(t_list *list, int nbr);
static int	ft_lst_search_down_exact(t_list *list, int nbr);
static int	ft_lst_search_up_aprox(t_list *list, int nbr);
static int	ft_lst_search_up_exact(t_list *list, int nbr);

int	ft_lst_search_nbr(t_list *list, int nbr, int mode)
{
	if (mode == 1)
	{
		return (ft_lst_search_down_aprox(list, nbr));
	}
	else if (mode == 2)
	{
		return (ft_lst_search_down_exact(list, nbr));
	}
	else if (mode == 3)
	{
		return (ft_lst_search_up_aprox(list, nbr));
	}
	else if (mode == 4)
	{
		return (ft_lst_search_up_exact(list, nbr));
	}
	return (-1);
}

static int	ft_lst_search_down_aprox(t_list *list, int nbr)
{
	int		counter;
	int		size;

	size = ft_lstsize(ft_lst_top(list));
	counter = 1;
	list = list->next;
	while (size != counter)
	{
		if (list->content < nbr)
			return (counter);
		if (list->next == 0)
			list = ft_lst_top(list);
		else
			list = list->next;
		counter++;
	}
	return (-1);
}

static int	ft_lst_search_down_exact(t_list *list, int nbr)
{
	int		counter;
	int		size;

	size = ft_lstsize(ft_lst_top(list));
	counter = 1;
	list = list->next;
	while (size != counter)
	{
		if (list->content == nbr)
			return (counter);
		if (list->next == 0)
			list = ft_lst_top(list);
		else
			list = list->next;
		counter++;
	}
	return (-1);
}

int	ft_lst_search_up_aprox(t_list *list, int nbr)
{
	int		counter;
	int		size;
	t_list	*aux;

	size = ft_lstsize(ft_lst_top(list));
	aux = ft_lstlast(list);
	counter = 1;
	while (size != counter)
	{
		if (aux->content < nbr)
			return (counter);
		counter++;
		if (aux->prev == 0)
			aux = ft_lstlast(list);
		else
			aux = aux->prev;
	}
	return (-1);
}

static int	ft_lst_search_up_exact(t_list *list, int nbr)
{
	int		counter;
	int		size;
	t_list	*aux;

	size = ft_lstsize(ft_lst_top(list));
	aux = ft_lstlast(list);
	counter = 1;
	while (size != counter)
	{
		if (aux->content == nbr)
			return (counter);
		counter++;
		if (aux->prev == 0)
			aux = ft_lstlast(list);
		else
			aux = aux->prev;
	}
	return (-1);
}
