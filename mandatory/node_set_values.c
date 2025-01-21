/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_set_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:12:25 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:04:14 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target(t_push *stack_a, t_push *stack_b)
{
	long	best_match;
	t_push	*target;
	t_push	*cur_a;

	while (stack_b)
	{
		best_match = LONG_MAX;
		cur_a = stack_a;
		while (cur_a)
		{
			if (cur_a->nb > stack_b->nb && cur_a->nb < best_match)
			{
				best_match = cur_a->nb;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target = ft_find_smallest(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

t_push	*ft_find_largest(t_push *stack)
{
	t_push	*largest;
	t_push	*cur;

	if (stack == NULL)
		return (NULL);
	cur = stack;
	largest = stack;
	while (cur)
	{
		if (cur->nb > largest->nb)
			largest = cur;
		cur = cur->next;
	}
	return (largest);
}

void	ft_target_b(t_push *stack_a, t_push *stack_b)
{
	long	best_match;
	t_push	*target;
	t_push	*cur_a;

	while (stack_a)
	{
		best_match = LONG_MIN;
		cur_a = stack_b;
		while (cur_a)
		{
			if (cur_a->nb < stack_a->nb && cur_a->nb > best_match)
			{
				best_match = cur_a->nb;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match == LONG_MIN)
			stack_a->target = ft_find_largest(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

int	ft_greater(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

void	ft_price(t_push *stack_a, t_push *stack_b)
{
	t_push	*trav;

	trav = stack_b;
	while (trav)
	{
		if (trav->cur_position <= (ft_listsize(stack_b) - 1) / 2
			&& trav->target->cur_position <= (ft_listsize(stack_a) - 1) / 2)
			trav->price = ft_greater(trav->cur_position, trav->target->cur_position);
		else if (trav->cur_position > (ft_listsize(stack_b) - 1) / 2
			&& trav->target->cur_position > (ft_listsize(stack_a) - 1) / 2)
			trav->price = ft_greater(ft_listsize(stack_b) - trav->cur_position, ft_listsize(stack_a)
					- trav->target->cur_position);
		else if (trav->cur_position <= (ft_listsize(stack_b) - 1) / 2
			&& trav->target->cur_position > (ft_listsize(stack_a) - 1) / 2)
			trav->price = trav->cur_position + ft_listsize(stack_a) - trav->target->cur_position;
		else
			trav->price = ft_listsize(stack_b) - trav->cur_position + trav->target->cur_position;
		trav = trav->next;
	}
}

void	ft_price_a(t_push *stack_a, t_push *stack_b)
{
	t_push	*trav;

	trav = stack_a;
	while (trav)
	{
		if (trav->cur_position <= (ft_listsize(stack_a) - 1) / 2
			&& trav->target->cur_position <= (ft_listsize(stack_b) - 1) / 2)
			trav->price = ft_greater(trav->cur_position, trav->target->cur_position);
		else if (trav->cur_position > (ft_listsize(stack_a) - 1) / 2
			&& trav->target->cur_position > (ft_listsize(stack_b) - 1) / 2)
			trav->price = ft_greater(ft_listsize(stack_a) - trav->cur_position, ft_listsize(stack_b)
					- trav->target->cur_position);
		else if (trav->cur_position <= (ft_listsize(stack_a) - 1) / 2
			&& trav->target->cur_position > (ft_listsize(stack_b) - 1) / 2)
			trav->price = trav->cur_position + ft_listsize(stack_b) - trav->target->cur_position;
		else
			trav->price = ft_listsize(stack_a) - trav->cur_position + trav->target->cur_position;
		trav = trav->next;
	}
}

void	ft_cur_position(t_push *stack)
{
	int	pos;
	int	mid;

	if (stack == NULL)
		return ;
	pos = 0;
	mid = (ft_listsize(stack) - 1) / 2;
	while (stack)
	{
		stack->cur_position = pos;
		if (pos <= mid)
			stack->upper = 1;
		else
			stack->upper = 0;
		stack = stack->next;
		pos++;
	}
}

void	ft_cheapest(t_push *stack_b)
{
	long	best_value;
	t_push	*best_node;

	if (stack_b == NULL)
		return ;
	best_value = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->price < best_value)
		{
			best_value = stack_b->price;
			best_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_node->cheapest = 1;
}

void	ft_init(t_push *stack_a, t_push *stack_b)
{
	ft_cur_position(stack_a);
	ft_cur_position(stack_b);
	ft_target(stack_a, stack_b);
	ft_price(stack_a, stack_b);
	ft_cheapest(stack_b);
}

void	ft_init_a(t_push *stack_a, t_push *stack_b)
{
	ft_cur_position(stack_a);
	ft_cur_position(stack_b);
	ft_target_b(stack_a, stack_b);
	ft_price_a(stack_a, stack_b);
	ft_cheapest(stack_a);
}
