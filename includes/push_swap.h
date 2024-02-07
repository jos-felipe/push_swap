/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/07 15:04:00 by gfantoni         ###   ########.fr       */
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

enum operations
{
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	PA,
	PB
};

typedef struct s_list_push
{
	int				value;
	int				index;
	struct s_list_push	*next;
}	t_list_push;


// 01_user_input_validation.c
void 	push_user_input_validation(int argc, char *argv[], t_bst **bst);
void	ft_int(int argc, char *argv[], t_bst **bst);
t_bst	*bst_insert_ps(t_bst **head, t_bst *node, int insert_key, bool *was_inserted);

// 02_indexing.c
void	push_fill_stack(t_list_push **a, int argc, char *argv[]);
void	push_bst_indexing(t_bst **bst, t_list_push **a);
void	bst_in_order_static(t_bst *node, int index);
t_list_push	*push_lstnew(int nbr);
void	push_lstadd_back(t_list_push **lst, t_list_push *new);
t_list_push	*push_lstlast(t_list_push *lst);
void	bst_in_order_print_index(t_bst *node);
void	push_lst_indexing(t_list_push *a, t_bst *bst);

// 03_moves.c
void		push_baby_moves(t_list_push **a, t_list_push **b);
void		push_gateway(int op, t_list_push **a, t_list_push **b);
void		push_do_sx(t_list_push **stack, char *sx);
void		push_lstprintf_value(t_list_push *lst);
void		push_lstadd_front(t_list_push **lst, t_list_push *new);
void		push_do_rrx(t_list_push **stack, char *rrx);
void		push_do_rx(t_list_push **stack, char *rx);
void		push_do_px(t_list_push **src, t_list_push **dest, char *px);
void		push_do_rrr(t_list_push **a, t_list_push **b, char *rrr);
void		push_do_rr(t_list_push **src, t_list_push **dest, char *rr);
void		push_do_ss(t_list_push **a, t_list_push **b, char *ss);
t_list_push	*push_lst_n_1(t_list_push *lst);

// 04_pre_sort.c
void	push_all_save_three(t_list_push **a, t_list_push **b);
void	push_tiny_sort(t_list_push **a);


// 99_utils.c
int		ft_is_zero(char *str);
void	free_heap(t_list *lst_memory);
void	push_safe_exit(	int status, \
						t_list_push **a, \
						t_list_push **b, \
						t_bst **bst);
void	push_lstclear(t_list_push **lst);
long	ft_atol(const char *nptr);
void	ft_xt_go_horse(char *str);
void	ft_error(t_bst **head);
int		ft_int_overflow(long nbr);
int		only_digit(char *str);

// 98_utils.c
void	push_lstprintf(t_list_push *lst);

// 96_utils.c
int		push_is_sorted(t_list_push *node);
int		push_lstsize(t_list_push *lst);
#endif