/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:06:32 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/21 09:24:47 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../Libft/libft.h"
# include "../map/map.h"
# include <mlx.h>

//man /usr/share/man/man3/mlx.1
void		start_game(t_data_map *data_map);
int			key_hook(int key_code, t_data_map *data_map);
t_window	*init_window(void);
void		draw_image(t_data_map *data_map, int y, int x);
void		set_window(t_data_map *data_map);
#endif