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
	t_counters	counters;

	stack_b = NULL;
	counters.count = 0;
	if (c < 4)
		ft_manualsort_a(stack_a);
	else if (c < 7)
	{
		ft_quicksort(stack_a, &stack_b, c, &counters);
		while (counters.count > 0)
		{
			ft_pa(stack_a, &stack_b);
			counters.count -= 1;
		}
	}
	else
		ft_algorithm(stack_a, &stack_b);
}
	// t_push *print;
	// print = *stack_a;
	// while (print)
	// {
	// 	ft_printf("%d\n", print->nb);
	// 	print = print->next;
	// }

void	ft_move_a(t_push **b, t_push **a)
{
	t_push	*cheapest;

	cheapest = ft_find_cheapest(*a);
	if (cheapest->upper == 1 && cheapest->target->upper == 1)
		ft_rotate_both(b, a, cheapest);
	else if (cheapest->upper == 0 && cheapest->target->upper == 0)
		ft_reverse_rotate_both(b, a, cheapest);
	ft_finish_rotation(a, cheapest, 'a');
	ft_finish_rotation(b, cheapest->target, 'b');
	ft_pb(b, a);
}

void	ft_push_to_b(t_push **stack_a, t_push **stack_b)
{
	if (ft_listsize(*stack_a) > 3 && ft_is_sorted(stack_a) == 0)
		ft_pb(stack_b, stack_a);
	if (ft_listsize(*stack_a) > 3 && ft_is_sorted(stack_a) == 0)
		ft_pb(stack_b, stack_a);
	while (ft_listsize(*stack_a) > 3 && ft_is_sorted(stack_a) == 0)
	{
		ft_init_a(*stack_a, *stack_b);
		ft_move_a(stack_b, stack_a);
	}
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

void	ft_finish_rotation(t_push **stack, t_push *cheapest, char c)
{
	while (*stack != cheapest)
	{
		if (c == 'a')
		{
			if (cheapest->upper == 1)
				ft_rotate_a(stack);
			else
				ft_reverse_a(stack);
		}
		else
		{
			if (cheapest->upper == 1)
				ft_rotate_b(stack);
			else
				ft_reverse_b(stack);
		}
	}
}
