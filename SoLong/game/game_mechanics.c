/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mechanics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:01:46 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/07 13:55:35 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_array_height(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}

int	get_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[0][i] != 0)
		i++;
	return (i);
}

t_window	*init_window(void)
{
	int		i;
	t_window *window;

	i = 32;
	window = ft_calloc(sizeof(t_window), 1);
	window->mlx_ptr = mlx_init();
	window->floor_title = mlx_xpm_file_to_image(window->mlx_ptr, "./img/Floor.xpm", &i, &i);
	window->player_title = mlx_xpm_file_to_image(window->mlx_ptr, "./img/Floor.xpm", &i, &i);
	window->wall_title = mlx_xpm_file_to_image(window->mlx_ptr, "./img/Wall.xpm", &i, &i);
	window->coin_title = mlx_xpm_file_to_image(window->mlx_ptr, "./img/Floor.xpm", &i, &i);
	return (window);
}

void	draw_image(t_data_map *data_map, int y, int x)
{
	t_window	*window;

	window = data_map->window;
	if (data_map->showmap[y][x] == '1')
		mlx_put_image_to_window(window->mlx_ptr,
			window->win_ptr, window->wall_title, x * 32, y * 32);
	else if (data_map->showmap[y][x] == '0')
		mlx_put_image_to_window(window->mlx_ptr,
			window->win_ptr, window->floor_title, x * 32, y * 32);
	else if (data_map->showmap[y][x] == 'C')
		mlx_put_image_to_window(window->mlx_ptr,
			window->win_ptr, window->coin_title, x * 32, y * 32);
	else if (data_map->showmap[y][x] == 'P')
		mlx_put_image_to_window(window->mlx_ptr,
			window->win_ptr, window->coin_title, x * 32, y * 32);
}

void	set_window(t_data_map *data_map)
{
	int	x;
	int	y;
	t_window *window;

	window = data_map->window;
	y = 0;
	while (data_map->showmap[y] != '\0')
	{
		x = 0;
		while (data_map->showmap[y][x] != '\0')
		{
			draw_image(data_map, y, x);
			x++;
		}
		y++;
	}
}

/*
	int	x;
	int	y;
	t_window *window;

	window = data_map->window;
	y = 0;
	while (data_map->showmap[y] != '\0')
	{
		x = 0;
		while (data_map->showmap[y][x] != '\0')
		{
			draw_image(data_map, y, x);
			x++;
		}
		y++;
	}
	*/

void	game_mechanics(t_data_map *data_map)
{
	int			x;
	int			y;
	t_window	*window;

	x = get_array_size(data_map->showmap);
	y = get_array_height(data_map->showmap);
	printf("X : %i , Y : %i\n", x, y);
	data_map->window = init_window();
	printf("Dir de suelo trass recibirse: %p\n",data_map->window->floor_title);
	window = data_map->window;
	window->win_ptr = mlx_new_window(data_map->window->mlx_ptr, x * 32, y * 32, "Prueba");
	//printf("Prueba?");
	set_window(data_map);
	//system("leaks -q a.out");
	mlx_loop(window->mlx_ptr);
}
