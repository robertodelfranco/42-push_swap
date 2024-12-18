/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:47:35 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 16:55:47 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../current_lib/Includes/libft.h"
#include "../current_lib/Includes/ft_printf_bonus.h"
#include "../current_lib/Includes/get_next_line_bonus.h"

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
