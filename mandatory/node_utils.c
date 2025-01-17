/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:52:06 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 15:22:19 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_find_smallest(t_push *stack)
{
	t_push	*smallest;
	t_push	*cur;

	if (stack == NULL)
		return (NULL);
	cur = stack;
	smallest = stack;
	while (cur)
	{
		if (cur->nb < smallest->nb)
			smallest = cur;
		cur = cur->next;
	}
	return (smallest);
}

t_push	*ft_find_cheapest(t_push *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
