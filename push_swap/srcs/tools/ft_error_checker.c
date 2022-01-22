/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:04:52 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 18:54:58 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int	ft_non_repeat(int i, int num, int *aux_list)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (num == aux_list[j] && (i != j))
			return (0);
		j++;
	}
	return (1);
}

static int	free_all(char **str_list, int *int_list, char *line, int f_int)
{
	int	i;
	int	tam;

	i = 0;
	tam = 0;
	while (str_list[tam] != 0)
	{
		tam++;
	}
	while (i < tam)
	{
		free(str_list[i++]);
	}
	free(str_list);
	free(line);
	if (f_int == 1)
		free(int_list);
	return (0);
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

static int	check_string(char *line, int i)
{
	char	**aux_str;
	int		*aux_list;
	int		num;
	int		tam;

	aux_str = ft_split(line, ' ');
	tam = ft_arraybi_size(aux_str);
	aux_list = ft_calloc(sizeof(int), tam);
	while (i < tam)
	{
		num = ft_atoi(aux_str[i]);
		if (num == 0 && ft_strncmp(aux_str[i], "0", ft_strlen(aux_str[i])))
		{
			free_all(aux_str, aux_list, line, 1);
			return (0);
		}
		aux_list[i] = num;
		if (ft_non_repeat(i, num, aux_list) == 0)
			return (free_all(aux_str, aux_list, line, 1));
		i++;
	}
	free_all(aux_str, aux_list, line, 1);
	return (1);
}

int	ft_error_checker(char **argv, int list_size)
{
	if (list_size == 1)
		return (0);
	return (check_string(makeline(argv), 0));
}
