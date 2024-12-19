/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:30:16 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/19 14:02:48 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **stack_a)
{
	ft_printf("ra\n");
	ft_rotate(stack_a);
}

void	ft_rotate_b(t_list **stack_b)
{
	ft_printf("rb\n");
	ft_rotate(stack_b);
}

void	ft_rotate_ss(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
}
