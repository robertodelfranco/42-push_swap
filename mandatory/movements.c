/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:43:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/23 14:35:28 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_push **stack)
{
	t_push	*start;
	t_push	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	start = *stack;
	second = (*stack)->next;
	start->next = second->next;
	second->next = start;
	*stack = second;
}

void	ft_push(t_push **push, t_push **stack)
{
	t_push	*temp;

	temp = (*push)->next;
	if (*stack != NULL)
	{
		(*push)->next = *stack;
		*stack = *push;
	}
	else
	{
		*stack = *push;
		(*stack)->next = NULL;
	}
	*push = temp;
}

void	ft_rotate(t_push **stack)
{
	t_push	*start;
	t_push	*last;

	start = *stack;
	last = ft_last(*stack);
	*stack = start->next;
	last->next = start;
	start->next = NULL;
}

void	ft_reverse(t_push **stack)
{
	t_push	*second_to_last;
	t_push	*start;
	t_push	*last;

	start = *stack;
	second_to_last = ft_second_to_last(*stack);
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = start;
	*stack = last;
}
