/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:43:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/19 14:40:08 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*start;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	start = *stack;
	second = (*stack)->next;
	start->next = second->next;
	second->next = start;
	*stack = second;
}

void ft_push(t_list **push, t_list **stack)
{
	t_list	*push_start;
	t_list	*stack_start;

	push_start = *push;
	stack_start = *stack;
	*push = push_start->next;
	push_start->next = stack_start;
	*stack = push_start;
}

void	ft_rotate(t_list **stack)
{
	t_list	*start;
	t_list	*last;

	start = *stack;
	last = ft_lstlast(*stack);
	*stack = start->next;
	last->next = start;
	start->next = NULL;
}

void	ft_reverse(t_list **stack)
{
	t_list	*second_to_last;
	t_list	*start;
	t_list	*last;

	start = *stack;
	second_to_last = ft_lstsecond_to_last(*stack);
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = start;
	*stack = last;
}
