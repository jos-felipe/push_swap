/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/03 18:32:25 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include "../lib/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list_push
{
	int				value;
	int				index;
	struct s_list_push	*next;
}	t_list_push;


// 01_user_input_validation.c
void 	ft_user_input_validation(int argc, char *argv[], t_bst **bst);
void	ft_int(int argc, char *argv[], t_bst **bst);
t_bst	*bst_insert_ps(t_bst **head, t_bst *node, int insert_key, bool *was_inserted);

// 02_indexing.c
void	ft_fill_stack(t_list_push **a, int argc, char *argv[]);
void	ft_bst_indexing(t_bst **bst, t_list_push **a);
void	bst_in_order_static(t_bst *node, int index);
t_list_push	*push_lstnew(int nbr);
void	push_lstadd_back(t_list_push **lst, t_list_push *new);
t_list_push	*push_lstlast(t_list_push *lst);
void	bst_in_order_print_index(t_bst *node);
void	ft_lst_indexing(t_list_push *a, t_bst *bst);

// 98_utils.c
void	push_lstprintf(t_list_push *lst);

// 99_utils.c
int		ft_is_zero(char *str);
void	free_heap(t_list *lst_memory);
void	ft_safe_exit(	int status, \
						t_list_push **a, \
						t_list_push **b, \
						t_bst **bst);
void	push_lstclear(t_list_push **lst);
long	ft_atol(const char *nptr);
void	ft_xt_go_horse(char *str);
void	ft_error(t_bst **head);
int		ft_int_overflow(long nbr);
int		only_digit(char *str);

#endif