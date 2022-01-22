/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mechanics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:01:46 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/21 17:57:47 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	delete_coin(t_data_map *data_map)
{
	ft_lstclear(data_map->list);
	data_map->list = create_objectlist(data_map->list, data_map->showmap);
}

int	check_coins(t_data_map *data_map)
{
	t_list	*aux;
	int		i;

	i = 0;
	aux = (*data_map->list);
	while (aux != 0)
	{
		if (aux->type == 'C')
			i++;
		aux = aux->next;
	}
	printf ("Monedas contadas : %i\n", i);
	return (i);
}

void	move_on_object(int x, int y, t_data_map *data_map)
{
	t_list	**player;
	t_list	**list;

	list = data_map->list;
	player = data_map->player;
	if (data_map->showmap[y][x] == 'C')
	{
		data_map->showmap[y][x] = '0';
		delete_coin(data_map);
		data_map->showmap[y][x] = 'P';
		data_map->showmap[(*player)->y_axis][(*player)->x_axis] = '0';
		draw_image(data_map, y, x);
		draw_image(data_map, (*player)->y_axis, (*player)->x_axis);
		(*player)->x_axis = x;
		(*player)->y_axis = y;
	}
	else if (data_map->showmap[y][x] == 'E')
	{
		if (check_coins(data_map) == 0)
		{
			data_map->showmap[(*player)->y_axis][(*player)->x_axis] = '0';
			draw_image(data_map, y, x);
			draw_image(data_map, (*player)->y_axis, (*player)->x_axis);
			printf("El personaje escapa");
		}
	}
}

void	move_character(int x, int y, t_data_map *data_map)
{
	t_list	**player;
	t_list	**list;

	list = data_map->list;
	player = data_map->player;
	data_map->showmap[y][x] = 'P';
	data_map->showmap[(*player)->y_axis][(*player)->x_axis] = '0';
	draw_image(data_map, y, x);
	draw_image(data_map, (*player)->y_axis, (*player)->x_axis);
	(*player)->x_axis = x;
	(*player)->y_axis = y;
}

void	check_movement_character(int x, int y, t_data_map *data_map)
{
	t_list	**player;
	char	**showmap;
	int		ply_new_x;
	int		ply_new_y;

	showmap = data_map->showmap;
	player = data_map->player;
	while ((*player) != 0)
	{
		ply_new_x = ((*player)->x_axis + x);
		ply_new_y = ((*player)->y_axis + y);
		if (showmap[ply_new_y][ply_new_x] == '1')
			printf("Se choca con un muro\n");
		else if (showmap[ply_new_y][ply_new_x] == 'P')
			printf("Se choca con un personaje\n");
		else if (showmap[ply_new_y][ply_new_x] == 'C')
			move_on_object(x, y, data_map);
		else if (showmap[ply_new_y][ply_new_x] == 'E')
			move_on_object(x, y, data_map);
		else
		{
			move_character(ply_new_x, ply_new_y, data_map);
		}
		if ((*player)->next == 0)
		{
			while ((*player)->prev != 0)
				(*player) = (*player)->prev;
			break ;
		}
		(*player) = (*player)->next;
	}
}

int	key_hook(int key_code, t_data_map *data_map)
{
	if (key_code == 0)
		check_movement_character(-1, 0, data_map);
	if (key_code == 13)
		check_movement_character(0, -1, data_map);
	if (key_code == 2)
		check_movement_character(1, 0, data_map);
	if (key_code == 1)
		check_movement_character(0, 1, data_map);
	if (key_code == 53)
		printf("Salimos del programa\n");
	printf("%i\n", key_code);
	return (0);
}
