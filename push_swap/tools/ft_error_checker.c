/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:04:52 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/14 12:31:27 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
static int	ft_non_repeat(int i, int num, int *aux_list);

int	ft_error_checker(char **argv, int list_size)
{
	int		*aux_list;
	int		num;
	int		i;

	i = 1;
	if (list_size == 0)
		return (0);
	aux_list = ft_calloc(sizeof(int), list_size);
	while (i < list_size)
	{
		num = ft_atoi(argv[i]);
		if (num == 0 && ft_strncmp(argv[i], "0", ft_strlen(argv[i])))
		{
			free(aux_list);
			return (0);
		}
		aux_list[i - 1] = num;
		if (ft_non_repeat(i - 1, num, aux_list) == 0)
			return (0);
		i++;
	}
	free(aux_list);
	return (1);
}

static int	ft_non_repeat(int i, int num, int *aux_list)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (num == aux_list[j] && (i != j))
		{
			free(aux_list);
			return (0);
		}
		j++;
	}
	return (1);
}
