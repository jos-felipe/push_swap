/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_user_input_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:43:20 by josfelip          #+#    #+#             */
/*   Updated: 2024/01/31 11:59:34 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_user_input_validation(int argc, char *argv[], t_list **trashman, t_bst **bst)
{
	int	*list;
	
	if (argc == 1)
		exit(1);
	list = ft_int(argc, argv, trashman);
	fill_bst(argc, bst, list);
	bst_in_order(*bst);
	bst_free_all(*bst);
	return ;
}

int	*ft_int(int argc, char *argv[], t_list **trashman)
{
	int		*list;
	int		i;
	long	nbr;

	list = (int *)calloc(sizeof(int), argc - 1);
	if (list == NULL)
		ft_xt_go_horse("Memory allocation failed");
	*trashman = ft_lstnew(list);
	i = 1;
	while (i < argc)
	{	
		if (!ft_is_zero(argv[i]))
		{
			nbr = ft_atol(argv[i]);
			ft_int_overflow(nbr, trashman);
			list[i-1] = (int)nbr;
			if (list[i-1] == 0)
				ft_error(trashman);
		}
		i++;
	}	
	return (list);
}

void	fill_bst(int argc, t_bst **bst, int *list)
{
	int		i;
	bool	was_inserted;

	i = 0;
	was_inserted = false; 
	while (i < argc - 1)
	{
		(*bst) = bst_insert((*bst), list[i], &was_inserted);
		i++;
	}
}