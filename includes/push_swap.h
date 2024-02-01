/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/01 19:36:31 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list_push
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list_push;


// 01_user_input_validation.c
void 	ft_user_input_validation(int argc, char *argv[], t_bst **bst);
void	ft_int(int argc, char *argv[], t_bst **bst);
t_bst	*bst_insert_ps(t_bst **head, t_bst *node, int insert_key, bool *was_inserted);

// 02_indexing.c
void	ft_indexing(t_bst **bst, t_list **a);
void	ft_fill_stack(t_list **a, int argc, char *argv);

// 99_utils.c
int		ft_is_zero(char *str);
void	free_heap(t_list *lst_memory);
void	ft_safe_exit(int status, t_list **trashman);
long	ft_atol(const char *nptr);
void	ft_xt_go_horse(char *str);
void	ft_error(t_bst **head);
void	ft_int_overflow(long nbr);
int	only_digit(char *str);

#endif