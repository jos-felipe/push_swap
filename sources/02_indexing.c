/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:05:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/01 20:03:40 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bst_in_order_static(t_bst *node)
{
	static int	index;
	
	index = ft_index_increment(index);
	if (node == NULL)
		return ;
	bst_in_order(node->left_child);
	node->index = index;
	bst_in_order(node->right_child);
}

void	ft_bst_indexing(t_bst **bst, t_list **a)
{
	
	return ;
}

void	ft_fill_stack(t_list **a, int argc, char *argv)
{
	int		i;
	long	nbr;
	
	i = 1;
	while (i < argc)
	{	
		nbr = ft_atol(argv[i]);
		ft_lstadd_back(a, ft_lstnew(nbr));
		i++;
	}	
}