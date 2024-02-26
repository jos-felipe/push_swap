/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:17:51 by gfantoni          #+#    #+#             */
/*   Updated: 2024/02/26 16:34:45 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
# define BST_H

//# include <limits.h>
# include "../../functions/includes/functions.h"

# define TRUE 1
# define FALSE 0

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_bst
{
	int				key;
	int				index;
	struct s_bst	*left_child;
	struct s_bst	*right_child;
}		t_bst;

void	bst_simple_print(t_bst *node, int depth);
int		bst_verify(t_bst *node, int minkey, int maxkey);
t_bst	*bst_create_node(int new_key);
t_bst	*bst_insert(t_bst *node, int insert_key, int *was_inserted);
int		bst_find_minimum(t_bst *node);
int		bst_find_maximum(t_bst *node);
int		bst_is_member(t_bst *node, int find_key);
t_bst	*bst_delete_node(t_bst *node, int delete_key, int *was_deleted);

void	bst_pre_order(t_bst *node);
void	bst_in_order(t_bst *node);
void	bst_reverse_in_order(t_bst *node);
void	bst_post_order(t_bst *node);
int		bst_num_nodes(t_bst *node);
void	bst_breadth_first(t_bst *node);
void	bst_free_all(t_bst *node);

t_bst	*left_right_child_null(t_bst *node, int *was_deleted);
t_bst	*left_child_null(t_bst *node, int *was_deleted);
t_bst	*right_child_null(t_bst *node, int *was_deleted);
t_bst	*left_right_child(t_bst *node, int *was_deleted);

#endif