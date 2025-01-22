/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:49:21 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:38:52 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_algorithms(t_push **stack_a, int c)
{
	t_push		*stack_b;

	stack_b = NULL;
	if (c < 4)
		ft_manualsort_a(stack_a);
	else
		ft_algorithm(stack_a, &stack_b);
}

void	ft_manualsort_a(t_push **stack)
{
	t_push	*highest_node;

	highest_node = ft_find_highest(*stack);
	if (*stack == highest_node)
		ft_rotate_a(stack);
	else if ((*stack)->next == highest_node)
		ft_reverse_a(stack);
	if ((*stack)->nb > (*stack)->next->nb)
		ft_swap_a(stack);
}

void	ft_algorithm(t_push **stack_a, t_push **stack_b)
{
	t_push	*smallest;

	ft_push_to_b(stack_a, stack_b);
	ft_manualsort_a(stack_a);
	while (*stack_b)
	{
		ft_init(*stack_a, *stack_b);
		ft_move(stack_a, stack_b);
	}
	ft_cur_position(*stack_a);
	smallest = ft_find_smallest(*stack_a);
	if (smallest->upper == 1)
		while (*stack_a != smallest)
			ft_rotate_a(stack_a);
	else
		while (*stack_a != smallest)
			ft_reverse_a(stack_a);
}

void	ft_move(t_push **stack_a, t_push **stack_b)
{
	t_push	*cheapest;

	cheapest = ft_find_cheapest(*stack_b);
	if (cheapest->upper == 1 && cheapest->target->upper == 1)
		ft_rotate_both(stack_a, stack_b, cheapest);
	else if (cheapest->upper == 0 && cheapest->target->upper == 0)
		ft_reverse_rotate_both(stack_a, stack_b, cheapest);
	ft_finish_rotation(stack_b, cheapest, 'b');
	ft_finish_rotation(stack_a, cheapest->target, 'a');
	ft_pa(stack_a, stack_b);
}

void	ft_init(t_push *stack_a, t_push *stack_b)
{
	ft_cur_position(stack_a);
	ft_cur_position(stack_b);
	ft_target(stack_a, stack_b);
	ft_price(stack_a, stack_b);
	ft_set_cheapest(stack_b);
}
