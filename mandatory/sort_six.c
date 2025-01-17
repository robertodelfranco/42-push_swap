/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:18:23 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:26:20 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_manualsort_a(t_push **stack)
{
	t_push	*highest_node;

	highest_node = find_highest(*stack);
	if (*stack == highest_node)
		ft_rotate_a(stack);
	else if ((*stack)->next == highest_node)
		ft_reverse_a(stack);
	if ((*stack)->nb > (*stack)->next->nb)
		ft_swap_a(stack);
}

void	ft_manualsort_b(t_push **stack, int c)
{
	while (!ft_reverse_sorted(stack))
	{
		if (c == 2)
			ft_swap_b(stack);
		else if (c == 3)
		{
			if ((*stack)->nb < (*stack)->next->nb && \
				(*stack)->nb < (*stack)->next->next->nb)
				ft_rotate_b(stack);
			else if ((*stack)->nb < (*stack)->next->nb)
				ft_swap_b(stack);
			else
				ft_reverse_b(stack);
		}
	}
}

void	ft_bubblesort(int	*list, int c)
{
	int	swap;
	int	i;

	i = 0;
	while (i < (c - 1))
	{
		if (list[i] > list[i + 1])
		{
			swap = list[i];
			list[i] = list[i + 1];
			list[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_quicksort(t_push **stack_a, t_push **stack_b,
		int size, t_counters *counter)
{
	int		pivot;
	int		i;

	i = 0;
	pivot = ft_find_pivot(stack_a, size);
	while (i < size)
	{
		if ((*stack_a)->nb < pivot)
		{
			ft_pb(stack_b, stack_a);
			counter->count += 1;
		}
		else if (ft_last(*stack_a)->nb < pivot)
		{
			ft_reverse_a(stack_a);
			ft_pb(stack_b, stack_a);
			counter->count += 1;
		}
		else if (!ft_implement_rotate(stack_a, pivot))
			ft_rotate_a(stack_a);
		i++;
	}
	ft_manualsort_a(stack_a);
	ft_manualsort_b(stack_b, counter->count);
}

t_push	*find_highest(t_push *stack)
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
