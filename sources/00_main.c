/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:11 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/06 19:27:07 by josfelip         ###   ########.fr       */
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
		ft_safe_exit(0, &a, &b, &bst);
	ft_fill_stack(&a, argc, argv);
	if (push_is_sorted(a))
		ft_safe_exit(0, &a, &b, &bst);
	ft_bst_indexing(&bst, &a);
	ft_lst_indexing(a, bst);
	if (DEBUG == 2) // _02_indexing.py
	{
		push_lstprintf(a);
		ft_safe_exit(0, &a, &b, &bst);
	}
	if (DEBUG == 3) // _03_moves.py
	{
		push_baby_moves(&a, &b);
		ft_safe_exit(0, &a, &b, &bst);
	}
	if (DEBUG == 4) // _04_pre_sort.py
	{
		push_lstprintf(a);
		push_lstprintf(b);
		ft_safe_exit(0, &a, &b, &bst);
	}
	ft_safe_exit(0, &a, &b, &bst);
}