/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:47:35 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 17:57:51 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{

	ft_printf("pa\n");
	if (*stack_b == NULL)
		return ;
	ft_push(&stack_a, &stack_b);
}

void	ft_push_b(t_list **stack_b, t_list **stack_a)
{
	ft_printf("pb\n");
	if (*stack_a == NULL)
		return ;
	ft_push(&stack_b, &stack_a);
}