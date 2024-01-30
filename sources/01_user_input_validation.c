/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_user_input_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:43:20 by josfelip          #+#    #+#             */
/*   Updated: 2024/01/30 17:33:47 by gfantoni         ###   ########.fr       */
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

#include <stdio.h>
void	ft_int(int argc, char *argv[], t_list **trashman)
{
	int	*list;
	int	i;

	list = (int *)calloc(sizeof(int), argc - 1);
	if (list == NULL)
	{
		ft_printf("Memory allocation failed");
		exit(1);
	}
	*trashman = ft_lstnew(list);
	i = 1;
	while (i < argc)
	{
		
		if (!ft_is_zero(argv[i]))
		{
			
			list[i-1] = ft_atoi(argv[i]);
			if (list[i-1] == 0)
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				ft_safe_exit(1, trashman);
			}
		}
		i++;
	}	
}
