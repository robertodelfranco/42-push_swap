/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:42:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 15:55:34 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../current_lib/Includes/libft.h"
#include "../current_lib/Includes/ft_printf_bonus.h"
#include "../current_lib/Includes/get_next_line_bonus.h"

void	ft_swap_a(t_list **stack_a)
{
	ft_printf("sa\n");
	ft_swap(&stack_a);
}

void	ft_swap_b(t_list **stack_b)
{
	ft_printf("sa\n");
	ft_swap(&stack_b);
}

void	ft_swap_ss(t_list **stack_a, t_list **stack_b)
{
	ft_printf("ss\n");
	ft_swap_a(&stack_a);
	ft_swap_b(&stack_b);
}
