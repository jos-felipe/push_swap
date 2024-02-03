/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:34:04 by josfelip          #+#    #+#             */
/*   Updated: 2024/02/03 18:54:17 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	free_heap(t_list *lst_memory)
{
	t_list	*tmp;

	while (lst_memory)
	{
		tmp = lst_memory;
		lst_memory = lst_memory->next;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_safe_exit(	int status, \
						t_list_push **a, \
						t_list_push **b, \
						t_bst **bst)
{
	if (a != NULL)
		push_lstclear(a);
	if (b != NULL)
		push_lstclear(b);
	if (bst != NULL)
		bst_free_all(*bst);
	if (status)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(status);
}

void	push_lstclear(t_list_push **lst)
{
	t_list_push	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
}


long	ft_atol(const char *nptr)
{
	long	sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' || \
			*nptr == '\f' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		nb = (*nptr - '0') + (nb * 10);
		nptr++;
	}
	return (nb * sign);
}

void	ft_xt_go_horse(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(1);
}

void	ft_error(t_bst **head)
{
	ft_putstr_fd("Error\n", 2);
	bst_free_all(*head);
	exit(1);
}

int	ft_int_overflow(long nbr)
{
	return (nbr > INT_MAX || nbr < INT_MIN);
}

int	only_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while(*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}