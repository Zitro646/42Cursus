/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:03:43 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/22 08:39:25 by mortiz-d         ###   ########.fr       */
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
int		ft_list_is_sorted(t_list *list);
int		ft_lst_get_nbrpos(t_list *lst, int nbr);
int		ft_lstisnbrmin(t_list *lst, int nbr);
int		ft_lstisnbrmax(t_list *lst, int nbr);
void	ft_map_array(t_list **list);
int		*ft_manage_chunks(int *oldchunk, int nbr, int command);
int		ft_lst_search_nbr(t_list *list, int nbr, int mode);
int		ft_lst_search_down_dst(t_list *list, int nbr);
t_list	*ft_lst_top(t_list *lst);
t_list	**ft_arrange_less_than_3(t_list **list_a);
t_list	**ft_arrange_less_than_5(t_list **list_a, t_list **list_b);
t_list	**ft_arrange_less_than_100(t_list **list_a, t_list **list_b);
t_list	**ft_arrange_more_than_100(t_list **list_a, t_list **list_b);
#endif