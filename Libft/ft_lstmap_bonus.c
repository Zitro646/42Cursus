/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:48:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 13:06:06 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_free_all(t_list *start);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*start;

	if (lst == NULL)
		return (0);
	aux = ft_lstnew(f(lst->content));
	if (aux == NULL)
		return (0);
	start = aux;
	while (lst != NULL)
	{
		lst = lst->next;
		if (lst != NULL)
		{
			aux->next = ft_lstnew(f(lst->content));
			aux = aux->next;
		}
		if (aux == NULL)
		{
			ft_lstclear(&start, del);
			ft_free_all(start);
			return (0);
		}
	}
	return (start);
}

static	void	ft_free_all(t_list *start)
{
	t_list	*aux;

	while (start != NULL)
	{
		aux = start;
		start = start->next;
		free(aux);
	}
	free(start);
}
