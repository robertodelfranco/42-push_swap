/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:53:35 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/23 15:59:28 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_push	*init_push_swap(int argc, char **argv)
{
	t_push	*push_swap;

	push_swap = (t_push *)malloc(sizeof(t_push));
	if (!push_swap)
		message_error(EXIT_FAILURE);
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->length_a = 0;
	push_swap->length_b = 0;
	push_swap->check_argv = FALSE;
	if (argc == 2)
	{
		push_swap->argv = (ft_split(argv[1], ' '));
		push_swap->check_argv = TRUE;
	}
	else
		push_swap->argv = ++argv;
	return (push_swap);
}

void	init_stacks(t_push *push_swap)
{
	size_t	index;
	long	nb;

	index = 0;
	nb = 0;
	while (push_swap->argv[index])
	{
		nb = ft_atol(push_swap->argv[index]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			free_and_close(push_swap, EXIT_FAILURE);
			return ;
		}
		link_node(&push_swap->stack_a, nb);
		index++;
	}
	push_swap->length_a = stack_length(push_swap->stack_a);
	set_position(push_swap->stack_a);
}

void	link_node(t_stack **stack, int nb)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = create_node(nb);
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
