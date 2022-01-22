/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:38:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/21 15:05:46 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

void	leaks(void)
{
	system("leaks -q game");
}

int	main(void)
{
	t_data_map	*map;

	//atexit(leaks);
	map = mapreader("mapa_1.ber");
	if (mapcheck(map) == -1)
		printf("Map Error");
	start_game(map);
	//system("leaks -q a.out");
}
/*
	t_list 		**list;
	t_list 		**player;
	int i;
	
	list = map->list;
	player = map->player;
	printf("\nMapa a mostrar\n");
	i = 0;
	while (map->showmap[i] != 0)
	{
		printf("%s\n", map->showmap[i]);
		i++;
	}
	printf("\nMapa de fondo\n");
	i = 0;
	while (map->showmap[i] != 0)
	{
		printf("%s\n", map->background_map[i]);
		i++;
	}

	printf("\nObjetos en la lista\n");
	while ((*list) != 0)
	{
		printf ("Objeto tipo : %c , Array pos[%i][%i]\n", (*list)->type, (*list)->y_axis, (*list)->x_axis);
		*list = (*list)->next;
	}
	printf("\nJugadores en la lista\n");
	while ((*player) != 0)
	{
		printf ("Objeto tipo : %c , Array pos[%i][%i]\n", (*player)->type, (*player)->y_axis, (*player)->x_axis);
		*player = (*player)->next;
	}

	return (0);
	*/