/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:11 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/02 11:21:23 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	t_bst		*bst;
	t_list_push	*a;
	t_list_push	*b;
	
	bst = NULL;
	a = NULL;
	b = NULL;
	ft_user_input_validation(argc, argv, &bst);
	ft_fill_stack(&a, argc, argv);
	ft_bst_indexing(&bst, &a);
	//bst_in_order(bst);
	bst_in_order_print_index(bst);
	bst_free_all(bst);
}