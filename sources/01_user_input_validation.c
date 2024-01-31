/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_user_input_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:43:20 by josfelip          #+#    #+#             */
/*   Updated: 2024/01/31 18:20:57 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_user_input_validation(int argc, char *argv[], t_bst **bst)
{
	int	*list;
	
	if (argc == 1)
		exit(1);
	ft_int(argc, argv, bst);
	return ;
}

void	ft_int(int argc, char *argv[], t_bst **bst)
{
	int		i;
	long	nbr;
	bool	was_inserted;

	was_inserted = false;
	i = 1;
	while (i < argc)
	{	
		if (!only_digit(argv[i]))
			ft_error(bst);
		nbr = ft_atol(argv[i]);
		ft_int_overflow(nbr);
		(*bst) = bst_insert_ps(bst, *bst, (int)nbr, &was_inserted);
		i++;
	}	
}

t_bst	*bst_insert_ps(t_bst **head, t_bst *node, int insert_key, bool *was_inserted)
{
	*was_inserted = false;
	if (node == NULL)
	{
		*was_inserted = true;
		return (bst_create_node(insert_key));
	}
	if (insert_key == node->key)
		ft_error(head);
	else if (insert_key > node->key)
	{
		node->right_child = bst_insert_ps(head, node->right_child, insert_key, was_inserted);
	}
	else if (insert_key < node->key)
	{
		node->left_child = bst_insert_ps(head, node->left_child, insert_key, was_inserted);
	}
	return (node);
}
