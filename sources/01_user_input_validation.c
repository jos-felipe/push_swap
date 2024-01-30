/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_user_input_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:43:20 by josfelip          #+#    #+#             */
/*   Updated: 2024/01/30 13:36:05 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_user_input_validation(int argc, char *argv[])
{
	if (argc == 1)
		exit(1);
	return ;
}

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
	ft_lstadd_back(trashman, ft_lstnew(list));
	i = 1;
	while (i < argc)
	{
		
		if (!ft_is_zero(argv[i]))
			list[i-1] = ft_atoi(argv[i]);
		i++;
		ft_printf("%d", list[i-1]);
	}
	
}

int	ft_is_zero(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	if (*str == '\0')
		return (1);
	return (0);
}
