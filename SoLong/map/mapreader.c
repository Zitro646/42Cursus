/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:31:10 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/07 08:09:26 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

char	**create_map(char **archive, int y_max)
{
	int			y;
	int			x;
	char		**procesed_map;
	char		*line;

	y = 0;
	x = 0;
	procesed_map = ft_calloc(sizeof(char *), y_max + 1);
	while (y < y_max)
	{
		line = ft_strdup(archive[y]);
		while (line[x] != '\0')
		{
			if (line[x] == 'E' || line[x] == 'C' || line[x] == 'P')
				line[x] = '0';
			x++;
		}
		procesed_map[y] = line;
		y++;
		x = 0;
	}
	return (procesed_map);
}

char	**create_showmap(char *str_dir, int y_max)
{
	int			fd;
	int			i;
	int			j;
	char		**show_map;

	i = 0;
	show_map = ft_calloc(sizeof(char *), y_max + 1);
	fd = open(str_dir, O_RDONLY);
	show_map[i] = get_next_line(fd);
	i = 0;
	while (show_map[i] != '\0')
	{
		j = 0;
		while (show_map[i][j] != '\0')
		{
			if (show_map[i][j] == '\n')
				show_map[i][j] = '\0';
			j++;
		}
		i++;
		show_map[i] = get_next_line(fd);
	}
	close(fd);
	return (show_map);
}

t_list	**create_objectlist(t_list **list, char **show_map, int y_max)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	list = ft_calloc(sizeof(t_list *), 1);
	while (y < y_max)
	{
		while (show_map[y][x] != '\0')
		{
			if (show_map[y][x] == 'C' || show_map[y][x] == 'E')
				ft_lstadd_back(list, ft_lstnew(show_map[y][x], x, y));
			x++;
		}
		y++;
		x = 0;
	}
	return (list);
}

t_list	**create_playerlist(t_list **player, char **show_map, int y_max)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	player = ft_calloc(sizeof(t_list *), 1);
	while (y < y_max)
	{
		while (show_map[y][x] != '\0')
		{
			if (show_map[y][x] == 'P')
				ft_lstadd_back(player, ft_lstnew(show_map[y][x], x, y));
			x++;
		}
		y++;
		x = 0;
	}
	return (player);
}

t_data_map	*mapreader(char *str_dir)
{
	int			height;
	t_data_map	*map;

	height = get_file_height(str_dir);
	if (height < 2)
		return (0);
	map = ft_calloc(sizeof(t_data_map), 1);
	map->showmap = create_showmap(str_dir, height);
	map->background_map = create_map(map->showmap, height);
	map->list = create_objectlist(map->list, map->showmap, height);
	map->player = create_playerlist(map->player, map->showmap, height);
	return (map);
}

/*

	t_list 		**list;
	t_list 		**player;
	int i;

	list = map->list;
	player = map->player;
	printf("\nMapa a mostrar\n");
	i = 0;
	while (i < height)
	{
		printf("%s\n", map->showmap[i]);
		i++;
	}
	printf("\nMapa de fondo\n");
	i = 0;
	while (i < height)
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
	*/

/*
int	get_file_size(char *str)
{	
	int		count;
	int		test;
	int		fd;
	char	*archive;

	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("(%d)Error al abrir el archivo.\n", fd);
		return (-1);
	}
	archive = 0;
	archive = get_next_line(fd);
	while (archive[count] != 0 && archive[count] != '\n')
		count++;
	while (archive)
	{
		test = 0;
		while (archive[test] != 0 && archive[test] != '\n')
			test++;
		free(archive);
		if (test != count)
			return (-1);
		archive = get_next_line(fd);
	}
	close(fd);
	return (count);
}
*/