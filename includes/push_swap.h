/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/01/30 16:01:05 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


// 01_user_input_validation.c
void	ft_user_input_validation(int argc, char *argv[], t_list **trashman);
void	ft_int(int argc, char *argv[], t_list **trashman);

// 99_utils.c
int		ft_is_zero(char *str);
void	ft_safe_exit(int status, t_list **trashman);

#endif