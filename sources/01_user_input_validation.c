/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_user_input_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:43:20 by josfelip          #+#    #+#             */
/*   Updated: 2024/01/30 20:59:42 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_user_input_validation(int argc, char *argv[], t_list **trashman)
{
	if (argc == 1)
		exit(1);
	ft_int(argc, argv, trashman);
	return ;
}

void	ft_int(int argc, char *argv[], t_list **trashman)
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
}

