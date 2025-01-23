/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:28:58 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/23 12:33:32 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rotate(t_push *push_swap, t_mv type, t_bool print_mv)
{
	if (type == ra)
	{
		execute_rotate(&push_swap->stack_a);
		if (print_mv)
			ft_printf("ra\n");
	}
	else if (type == rb)
	{
		execute_rotate(&push_swap->stack_b);
		if (print_mv)
			ft_printf("rb\n");
	}
	else if (type == rr)
	{
		execute_rotate(&push_swap->stack_a);
		execute_rotate(&push_swap->stack_b);
		if (print_mv)
			ft_printf("rr\n");
	}
}

void	execute_rotate(t_stack **stack)
{
	t_stack	*current_last;
	t_stack	*new_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current_last = find_last_node(*stack);
	new_last = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current_last->next = new_last;
	new_last->prev = current_last;
	new_last->next = NULL;
}
