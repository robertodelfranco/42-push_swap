/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:30:16 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:18:00 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_push **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_push **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rotate_ss(t_push **stack_a, t_push **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}

void	ft_rotate_both(t_push **stack_a, t_push **stack_b, t_push *cheapest)
{
	while (*stack_a != cheapest->target && *stack_b != cheapest)
		ft_rotate_ss(stack_a, stack_b);
	ft_cur_position(*stack_a);
	ft_cur_position(*stack_b);
}

void	ft_rotate(t_push **stack)
{
	t_push	*last;
	int		len;

	len = ft_listsize(*stack);
	if (stack == NULL || *stack == NULL || len < 2)
		return ;
	last = ft_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}
