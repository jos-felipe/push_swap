/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/01/31 11:52:46 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


// 01_user_input_validation.c
void	ft_user_input_validation(int argc, char *argv[], t_list **trashman, t_bst **bst);
int		*ft_int(int argc, char *argv[], t_list **trashman);
void	fill_bst(int argc, t_bst **bst, int *list);

// 99_utils.c
int		ft_is_zero(char *str);
void	free_heap(t_list *lst_memory);
void	ft_safe_exit(int status, t_list **trashman);
long	ft_atol(const char *nptr);
void	ft_xt_go_horse(char *str);
void	ft_error(t_list **trashman);
void	ft_int_overflow(long nbr, t_list **trashman);

#endif