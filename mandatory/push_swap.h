/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:54:12 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 18:09:51 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../current_lib/Includes/libft.h"
# include "../current_lib/Includes/ft_printf_bonus.h"
# include "../current_lib/Includes/get_next_line_bonus.h"

void	ft_reverse(t_list **stack);
void	ft_reverse_a(t_list **stack_a);
void	ft_reverse_b(t_list **stack_b);
void	ft_reverse_ss(t_list **stack_a, t_list **stack_b);

void	ft_rotate(t_list **stack);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_rotate_ss(t_list **stack_a, t_list **stack_b);

void	ft_push(t_list **push, t_list **stack);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_push_b(t_list **stack_a, t_list **stack_b);

void	ft_swap(t_list **stack);
void	ft_swap_a(t_list **stack_a);
void	ft_swap_b(t_list **stack_b);
void	ft_swap_ss(t_list **stack_a, t_list **stack_b);

void	ft_free(char **ptr_matrix, int j);

int		ft_validate(int *c, char **v, int ent);
int		ft_check_numbers(char **str);

t_list	*ft_create_list(int count, char **v);

#endif