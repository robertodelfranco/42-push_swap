/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:30:16 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 15:55:30 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../current_lib/Includes/libft.h"
#include "../current_lib/Includes/ft_printf_bonus.h"
#include "../current_lib/Includes/get_next_line_bonus.h"

void	ft_rotate_a(t_list **stack_a)
{
	ft_printf("ra\n");
	ft_rotate(&stack_a);
}

void	ft_rotate_b(t_list **stack_b)
{
	ft_printf("rb\n");
	ft_rotate(&stack_b);
}

void	ft_rotate_ss(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_a(&stack_a);
	ft_rotate_b(&stack_b);
}
