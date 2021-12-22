/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:27:57 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/21 15:01:25 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
void	ft_pb(t_list **list_a, t_list **list_b, int show)
{
	t_list	*aux;

	if (*list_b != 0)
	{
		aux = ft_lstnew((*list_a)->content);
		ft_lstadd_front(&(*list_b), aux);
	}
	else
	{
		aux = ft_lstnew((*list_a)->content);
		*list_b = aux;
	}
	aux = (*list_a)->next;
	ft_lstdelone(*list_a);
	*list_a = aux;
	if (list_a != 0)
		(*list_a)->prev = 0;
	if (show == 1)
		printf("pb\n");
}

/*
int	lookarrays(int *list_a, int *list_b, int list_size)
{
	int		i;

	printf("a ----- b\n");
	i = 0;
	while (i < list_size)
	{
		if (list_a[i] == '\0')
			printf(" -----");
		else
			printf("%i -----", list_a[i]);
		if (list_b[i] == '\0')
			printf(" \n");
		else
			printf("%i\n", list_b[i]);
		i++;
	}
	return (0);
}

int main(void)
{
	int	*list_a;
	int	*list_b;

	list_a = ft_calloc(sizeof(int), 6);
	list_a[0] = 1;
	list_a[1] = 2;
	list_a[2] = 3;
	list_a[3] = 4;
	list_b = ft_calloc(sizeof(int), 6);
	list_b[0] = 5;
	ft_pb(list_a, list_b);
	lookarrays(list_a, list_b, 6);
	return (1);
}
*/
//gcc -Wall -Werror -Wextra ./operations/ft_pb.c ./libft/ft_count_list.c ./libft/ft_calloc.c ./libft/ft_bzero.c && ./a.out
