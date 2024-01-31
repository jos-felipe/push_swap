/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:11 by josfelip          #+#    #+#             */
/*   Updated: 2024/01/31 18:00:17 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	t_bst	*bst;
	
	bst = NULL;
	ft_user_input_validation(argc, argv, &bst);
	bst_free_all(bst);
}