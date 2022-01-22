/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starter_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:44:35 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 18:12:53 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static t_list	**ft_read_line(t_list **list_a, char *line)
{
	int		i;	
	int		num;
	t_list	*aux;
	char	**lst;

	list_a = 0;
	i = 0;
	num = 0;
	list_a = ft_calloc(sizeof(t_list), 1);
	lst = ft_split(line, ' ');
	while (lst[i] != '\0')
	{
		num = ft_atoi(lst[i]);
		aux = ft_lstnew(num);
		ft_lstadd_back(list_a, aux);
		free(lst[i]);
		i++;
	}
	free(lst);
	free(line);
	return (list_a);
}

static char	*makeline(char **argv)
{
	int		i;
	char	*aux;
	char	*aux2;
	char	*aux3;

	i = 1;
	aux = ft_strdup(" ");
	while (argv[i] != 0)
	{
		aux2 = ft_strjoin(" ", argv[i]);
		aux3 = aux;
		aux = ft_strjoin(aux3, aux2);
		free(aux2);
		free(aux3);
		i++;
	}
	return (aux);
}

t_list	**ft_starter_array(t_list **list_a, char **argv, int list_size)
{
	if (list_size == 1)
		return (list_a);
	list_a = ft_read_line(list_a, makeline(argv));
	return (list_a);
}
