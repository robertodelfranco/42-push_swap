/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:36:18 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/23 17:21:41 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_a(t_push **stack_a)
{
	ft_printf("rra\n");
	ft_reverse(stack_a);
}

void	ft_reverse_b(t_push **stack_b)
{
	ft_printf("rrb\n");
	ft_reverse(stack_b);
}

void	ft_reverse_ss(t_push **stack_a, t_push **stack_b)
{
	ft_reverse_a(stack_a);
	ft_reverse_b(stack_b);
}
