/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:11 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/03 15:15:40 by gfantoni         ###   ########.fr       */
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
	if (DEBUG == 1) // _01_user_input_validation.py
		ft_safe_exit(1, &a, &b, &bst);
	ft_fill_stack(&a, argc, argv);
	ft_bst_indexing(&bst, &a);
	ft_lst_indexing(a, bst);
	if (DEBUG == 2) // _02_indexing.py
	{
		push_lstprintf(a);
		ft_safe_exit(1, &a, &b, &bst);
	}
	ft_safe_exit(1, &a, &b, &bst);
}