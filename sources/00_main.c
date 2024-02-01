/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:11 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/01 19:38:03 by josfelip         ###   ########.fr       */
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
	ft_indexing(&bst, &a);
	bst_in_order(bst);
	bst_free_all(bst);
}