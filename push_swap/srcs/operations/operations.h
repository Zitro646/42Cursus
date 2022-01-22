/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:12:28 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/15 11:22:14 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "../libft/libft.h"
# include <stdio.h>

void	ft_sa(t_list **list_a, int show);
void	ft_sb(t_list **list_b, int show);
void	ft_ss(t_list **list_a, t_list **list_b, int show);
void	ft_pa(t_list **list_a, t_list **list_b, int show);
void	ft_pb(t_list **list_a, t_list **list_b, int show);
void	ft_ra(t_list **list_a, int show);
void	ft_rb(t_list **list_b, int show);
void	ft_rr(t_list **list_a, t_list **list_b, int show);
void	ft_rra(t_list **list_a, int show);
void	ft_rrb(t_list **list_b, int show);
void	ft_rrr(t_list **list_a, t_list **list_b, int show);

#endif