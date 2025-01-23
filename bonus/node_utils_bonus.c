/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:54:59 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/23 13:04:23 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t	stack_length(t_stack *stack)
{
	size_t	length;

	if (stack == NULL)
		return (0);
	length = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

t_bool	check_ordered(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (FALSE);
	temp = stack;
	while (temp->next)
	{
		if (temp->nb > temp->next->nb)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

void	set_position(t_stack *stack)
{
	int	current_position;
	int	center_line;

	if (stack == NULL)
		return ;
	current_position = 0;
	center_line = stack_length(stack) / 2;
	while (stack != NULL)
	{
		stack->pos = current_position;
		if (current_position <= center_line)
			stack->above_center = TRUE;
		else if (current_position > center_line)
			stack->above_center = FALSE;
		stack = stack->next;
		++current_position;
	}
}
