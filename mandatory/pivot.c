/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:03 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:22:14 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_pivot(t_push **list, int c)
{
	int		*array;
	int		n;
	int		i;

	if (c == 1)
		return ((*list)->nb);
	array = ft_create_array(list, c);
	ft_bubblesort(array, c);
	i = 0;
	while (i < (c / 2))
		i++;
	n = array[i];
	free(array);
	return (n);
}

int	ft_implement_rotate(t_push **stack_a, int pivot)
{
	t_push	*nav;

	nav = *stack_a;
	while (nav != NULL)
	{
		if (nav->nb < pivot)
			return (0);
		nav = nav->next;
	}
	return (1);
}

int	ft_compare(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

int	*ft_create_array(t_push **list, int count)
{
	int		*stack;
	t_push	*nav;
	int		i;

	nav = *list;
	stack = (int *)malloc(sizeof(int) * count);
	i = 0;
	while (nav != NULL)
	{
		stack[i] = nav->nb;
		nav = nav->next;
		i++;
	}
	return (stack);
}

int	ft_reverse_sorted(t_push **stack)
{
	t_push	*nav;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	nav = *stack;
	while (nav->next != NULL)
	{
		if (nav->nb < nav->next->nb)
			return (0);
		nav = nav->next;
	}
	return (1);
}
