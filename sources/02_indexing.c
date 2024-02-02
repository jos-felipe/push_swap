/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:05:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/02 11:40:32 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_fill_stack(t_list_push **a, int argc, char *argv[])
{
	int		i;
	long	nbr;
	
	i = 1;
	while (i < argc)
	{	
		nbr = ft_atol(argv[i]);
		push_lstadd_back(a, push_lstnew(nbr));
		i++;
	}	
}

void	ft_bst_indexing(t_bst **bst, t_list_push **a)
{

	bst_in_order_static(*bst, 0);
	a = NULL;
	return ;
}

void	bst_in_order_static(t_bst *node, int layer)
{
	static int	index;
	
	if (layer == 0)
		index = 1;
	if (node == NULL)
		return ;
	bst_in_order_static(node->left_child, layer + 1);
	node->index = index;
	index++;	
	bst_in_order_static(node->right_child, layer + 1);
}

void	bst_in_order_print_index(t_bst *node) // REMOVE
{
	if (node == NULL)
		return ;
	bst_in_order_print_index(node->left_child);
	ft_printf("node: %d, index: %d\n", node->key, node->index);
	bst_in_order_print_index(node->right_child);
}

