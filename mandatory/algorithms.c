/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:18:23 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 09:02:34 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_algorithm(t_push **stack_a, int c)
{
	t_push		*stack_b;
	t_counters	counters;

	stack_b = NULL;
	counters.count = 0;
	if (c < 4)
		ft_manualsort_a(stack_a, c);
	else if (c < 7)
		ft_quicksort(stack_a, &stack_b, c, &counters);
	// else
	// 	ft_bigger_algo(stack_a, &stack_b, c);
}

void	ft_manualsort_a(t_push **stack, int c)
{
	while (!ft_is_sorted(stack))
	{
		if (c == 2)
			ft_swap_a(stack);
		else if (c == 3)
		{
			if ((*stack)->nb > (*stack)->next->nb && \
				(*stack)->nb > (*stack)->next->next->nb)
				ft_rotate_a(stack);
			else if ((*stack)->nb > (*stack)->next->nb)
				ft_swap_a(stack);
			else
				ft_reverse_a(stack);
		}
	}
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
			ft_push_b(stack_a, stack_b);
			counter->count += 1;
		}
		else if (!ft_implement_rotate(stack_a, pivot))
			ft_rotate_a(stack_a);
		i++;
	}
	ft_manualsort_a(stack_a, size - counter->count);
	ft_manualsort_b(stack_b, counter->count);
	while (counter->count > 0)
	{
		ft_push_a(stack_b, stack_a);
		counter->count -= 1;
	}
}
