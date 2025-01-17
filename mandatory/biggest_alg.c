/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:32:30 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 12:03:40 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check movements of push that has to contain prev pointer

void	ft_bigger_algo(t_push **stack_a, t_push **stack_b, int size)
{
	
}

void	ft_price(t_push *stack_a, t_push *stack_b, int pivot)
{
	int		len_a;
	int		len_b;

	len_a = ft_listsize(stack_a);
	len_b = ft_listsize(stack_b);
	while (stack_b)
	{
		stack_b->price = stack_b->cur_position;
		if (stack_b > pivot)
			stack_b->price = len_b - stack_b->cur_position;
		if (stack_b <= pivot)
			stack_b->price += stack_b->target->cur_position;
		else
			stack_b->price += len_a - stack_b->target->cur_position;
		stack_b = stack_b->next;
	}
}
