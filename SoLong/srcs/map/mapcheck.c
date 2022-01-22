/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:24:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/21 15:02:21 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

int	check_file_borders(char **map_background, int count, int i)
{	
	int		test;

	while (map_background[0][count] != 0)
		count++;
	while (map_background[i])
	{
		test = 0;
		while (map_background[i][test] != 0)
			test++;
		if (test != count)
			return (-1);
		if (map_background[i][0] != '1' || map_background[i][count - 1] != '1')
			return (-2);
		i++;
	}
	count = 0;
	while (map_background[0][count] != '\0')
	{
		if (map_background[0][count] != '1' || \
			map_background[i - 1][count] != '1')
			return (-2);
		count++;
	}
	return (1);
}

int	check_object_numbers(t_list *list, t_list *player)
{
	int		exit_count;
	int		coin_count;
	int		player_count;

	exit_count = 0;
	coin_count = 0;
	player_count = 0;
	while (list != 0)
	{
		if (list->type == 'C')
			coin_count++;
		if (list->type == 'E')
			exit_count++;
		list = list->next;
	}
	if (player != 0)
		player_count = 1;
	if (coin_count < 1 || exit_count < 1 || player_count < 1)
		return (-1);
	return (1);
}

int	mapcheck(t_data_map *map)
{
	int	check_border;
	int	check_objects;

	if (map == NULL)
		return (-1);
	check_border = check_file_borders((map)->background_map, 0, 0);
	check_objects = 1;
	check_objects = check_object_numbers(*(map)->list, *(map)->player);
	if (check_border == 1 && check_objects == 1)
		return (1);
	else
		return (-1);
}
