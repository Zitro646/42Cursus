/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:03:43 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/19 15:13:10 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include "../libft/libft.h"
# include "../operations/operations.h"
# include <stdio.h>

t_list	**ft_starter_array(t_list **list_a, char **argv, int list_size);
int		ft_error_checker(char **argv, int list_size);
int		ft_look_arrays(t_list *list_a, t_list *list_b);
t_list	**ft_map_array(t_list **list);
t_list	**ft_arrange_less_than_3(t_list **list_a);
t_list	**ft_arrange_less_than_5(t_list **list_a, t_list **list_b);
t_list	**ft_arrange_more_than_5(t_list **list_a, t_list **list_b, int div);

#endif