/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:06:32 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/07 08:10:03 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../Libft/libft.h"
# include "../map/map.h"
# include <mlx.h>

//man /usr/share/man/man3/mlx.1
void	game_mechanics(t_data_map *data_map);
#endif