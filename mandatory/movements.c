/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:43:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 17:11:52 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../current_lib/Includes/libft.h"
#include "../current_lib/Includes/ft_printf_bonus.h"
#include "../current_lib/Includes/get_next_line_bonus.h"

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
	*stack = stack_start->next;
	stack_start->next = push_start;
	*push = stack_start;
}
