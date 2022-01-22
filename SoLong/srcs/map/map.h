/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:34:09 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/21 17:27:14 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor_title;
	void	*player_title;
	void	*exit_title;
	void	*wall_title;
	void	*coin_title;
}	t_window;

typedef struct data_map
{
	char		**background_map;
	char		**showmap;
	t_window	*window;
	t_list		**list;
	t_list		**player;
}	t_data_map;

t_data_map	*mapreader(char *str_dir);
int			mapcheck(t_data_map *map);
int			get_file_height(char *str);
t_list		**create_objectlist(t_list **list, char **show_map);
t_list		**create_playerlist(t_list **player, char **show_map, int y_max);
#endif
