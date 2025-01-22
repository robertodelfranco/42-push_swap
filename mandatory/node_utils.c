/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:52:06 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 15:22:19 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_find_smallest(t_push *stack)
{
	t_push	*smallest;
	t_push	*cur;

	if (stack == NULL)
		return (NULL);
	cur = stack;
	smallest = stack;
	while (cur)
	{
		if (cur->nb < smallest->nb)
			smallest = cur;
		cur = cur->next;
	}
	return (smallest);
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

t_push	*ft_find_cheapest(t_push *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_push	*ft_find_highest(t_push *stack)
{
	int		highest;
	t_push	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->nb > highest)
		{
			highest = stack->nb;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	ft_set_cheapest(t_push *stack_b)
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
