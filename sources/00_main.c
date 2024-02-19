/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:11 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/19 13:10:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	t_bst		*bst;
	t_list_push	*a;
	t_list_push	*b;
	int			rotations[2];
	
	bst = NULL;
	a = NULL;
	b = NULL;
	push_user_input_validation(argc, argv, &bst);
	if (DEBUG == 1) // _01_user_input_validation.py
		push_safe_exit(0, &a, &b, &bst);
	push_fill_stack(&a, argc, argv);
	if (push_is_sorted(a))
		push_safe_exit(0, &a, &b, &bst);
	push_bst_indexing(&bst, &a);
	push_lst_indexing(a, bst);
	if (DEBUG == 2) // _02_indexing.py
	{
		push_lstprintf_index(a);
		push_safe_exit(0, &a, &b, &bst);
	}
	if (DEBUG == 3) // _03_moves.py
	{
		push_baby_moves(&a, &b);
		push_safe_exit(0, &a, &b, &bst);
	}
	push_only_swap_sort(&a, &b, &bst);
	push_all_save_three(&a, &b);
	push_tiny_sort(&a);
	if (DEBUG == 4) // _04_pre_sort.py
	{
		push_lstprintf_value(a);
		if (b != NULL)
			push_lstprintf_value(b);
		push_safe_exit(0, &a, &b, &bst);
	}
	push_target_pos(a, b);
	if (DEBUG == 5) // _05_target_position.py
	{
		push_lstprintf_target_pos(b);
		push_safe_exit(0, &a, &b, &bst);
	}
	push_comp_cost(a, b);
	if (DEBUG == 6) // _06_comp_cost.py
	{
		push_lstprintf_cost(b);
		push_safe_exit(0, &a, &b, &bst);
	}
	push_cheapest_move(b, rotations);
	if (DEBUG == 7) // _07_cheapest_move.py
	{
		ft_printf("[%d,%d]\n", rotations[0], rotations[1]);
		push_safe_exit(0, &a, &b, &bst);
	}
	push_sort(&a, &b, rotations);
	if (DEBUG == 8) // _08_sort.py
	{
		push_lstprintf_index(a);
		ft_printf("\n");
		push_lstprintf_index(b);
		ft_printf("\n");
		push_safe_exit(0, &a, &b, &bst);
	}
	push_safe_exit(0, &a, &b, &bst);
}