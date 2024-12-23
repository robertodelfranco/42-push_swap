/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:18:23 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/23 18:45:16 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_algorithm(t_list **stack_a, int c)
{
	t_list		*stack_b;
	t_counters	counters;

	stack_b = NULL;
	counters.count = 0;
	if (c < 4)
		ft_manualsort_a(stack_a, c);
	else
		ft_quicksort(stack_a, &stack_b, c, &counters);
}

void	ft_manualsort_a(t_list **stack, int c)
{
	while (!ft_is_sorted(stack))
	{
		if (c == 2)
			ft_swap_a(stack);
		else if (c == 3)
		{
			if ((*stack)->nb > (*stack)->next->nb &&
				(*stack)->nb > (*stack)->next->next->nb)
				ft_rotate_a(stack);
			else if ((*stack)->nb > (*stack)->next->nb)
				ft_swap_a(stack);
			else
				ft_reverse_a(stack);
		}
	}	
}

void	ft_manualsort_b(t_list **stack, int c)
{
	while (!ft_reverse_sorted(stack))
	{
		if (c == 2)
			ft_swap_b(stack);
		else if (c == 3)
		{
			if ((*stack)->nb < (*stack)->next->nb &&
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
	while(i < (c - 1))
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

void	ft_quicksort(t_list **stack_a, t_list **stack_b, int size, t_counters *counter)
{
	int		pivot;
	int		i;

	if (size <= 3)
		return (ft_manualsort_a(stack_a, size), ft_manualsort_b(stack_b, counter->count));
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
	ft_quicksort(stack_a, stack_b, size - counter->count, counter);
	ft_quicksort(stack_a, stack_b, counter->count, counter);
	while (counter->count > 0)
	{
		ft_push_a(stack_b, stack_a);
		counter->count -= 1;
	}
}

	// t_list *nav1;
	// nav1 = *stack_a;
	// ft_printf("A: ");
	// while (nav1)
	// {
	// 	ft_printf("%d ", nav1->nb);
	// 	nav1 = nav1->next;
	// }
	// ft_printf("\n");
	// t_list *nav;
	// nav = *stack_b;
	// ft_printf("B: ");
	// while (nav)
	// {
	// 	ft_printf("%d ", nav->nb);
	// 	nav = nav->next;
	// }
	// ft_printf("\n");