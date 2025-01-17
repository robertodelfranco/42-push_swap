/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:36:18 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:18:11 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_a(t_push **stack_a)
{
	ft_reverse(stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_b(t_push **stack_b)
{
	ft_reverse(stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_ss(t_push **stack_a, t_push **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	ft_printf("rrr\n");
}

void	ft_reverse_rotate_both(t_push **stack_a, t_push **stack_b,
			t_push *cheapest)
{
	while (*stack_a != cheapest->target && *stack_b != cheapest)
		ft_reverse_ss(stack_a, stack_b);
	ft_cur_position(*stack_a);
	ft_cur_position(*stack_b);
}

void	ft_reverse(t_push **stack)
{
	t_push	*last;
	int		len;

	len = ft_listsize(*stack);
	if (stack == NULL || *stack == NULL || len < 2)
		return ;
	last = ft_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
