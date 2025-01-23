/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:29:06 by marvin            #+#    #+#             */
/*   Updated: 2025/01/23 11:18:44 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_price_a(t_push *stack_a, t_push *stack_b)
{
	t_push	*tr;

	tr = stack_a;
	while (tr)
	{
		if (tr->cur_position <= (ft_listsize(stack_a) - 1) / 2
			&& tr->target->cur_position <= (ft_listsize(stack_b) - 1) / 2)
			tr->price = ft_greater(tr->cur_position, tr->target->cur_position);
		else if (tr->cur_position > (ft_listsize(stack_a) - 1) / 2
			&& tr->target->cur_position > (ft_listsize(stack_b) - 1) / 2)
			tr->price = ft_greater(ft_listsize(stack_a) - tr->cur_position,
					ft_listsize(stack_b) - tr->target->cur_position);
		else if (tr->cur_position <= (ft_listsize(stack_a) - 1) / 2
			&& tr->target->cur_position > (ft_listsize(stack_b) - 1) / 2)
			tr->price = tr->cur_position + ft_listsize(stack_b)
				- tr->target->cur_position;
		else
			tr->price = ft_listsize(stack_a) - tr->cur_position
				+ tr->target->cur_position;
		tr = tr->next;
	}
}

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

int	ft_greater(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
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
