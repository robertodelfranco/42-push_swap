/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:43:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 11:49:11 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_push **stack)
{
	int	len;

	len = ft_listsize(*stack);
	if (stack == NULL || *stack == NULL || len < 2)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	ft_push(t_push **push, t_push **stack)
{
	t_push	*temp;

	if (*push == NULL)
		return ;
	temp = *push;
	*push = (*push)->next;
	if (*push)
		(*push)->prev = NULL;
	temp->prev = NULL;
	if (*stack == NULL)
	{
		*stack = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack;
		temp->next->prev = temp;
		*stack = temp;
	}
}

void	ft_rotate(t_push **stack)
{
	t_push	*last;
	int		len;

	len = ft_listsize(*stack);
	if (stack == NULL || *stack == NULL || len < 2)
		return ;
	last = ft_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ft_reverse(t_push **stack)
{
	t_push	*last;
	int		len;

	len = ft_listsize(*stack);
	if (stack == NULL || *stack == NULL || len < 2)
		return ;
	last = ft_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
