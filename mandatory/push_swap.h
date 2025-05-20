/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:54:12 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:25:25 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"
# include "../current_lib/Includes/libft.h"
# include "../current_lib/Includes/ft_printf_bonus.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_push
{
	int				nb;
	int				upper;
	int				price;
	int				cheapest;
	int				cur_position;
	struct s_push	*next;
	struct s_push	*prev;
	struct s_push	*target;
}				t_push;

// op_reverse //
void	ft_reverse_a(t_push **stack_a);
void	ft_reverse_b(t_push **stack_b);
void	ft_reverse_ss(t_push **stack_a, t_push **stack_b);
void	ft_reverse_rotate_both(t_push **stack_a, t_push **stack_b,
			t_push *cheapest);
void	ft_reverse(t_push **stack);

// op_rotate //
void	ft_rotate_a(t_push **stack_a);
void	ft_rotate_b(t_push **stack_b);
void	ft_rotate_ss(t_push **stack_a, t_push **stack_b);
void	ft_rotate_both(t_push **stack_a, t_push **stack_b, t_push *cheapest);
void	ft_rotate(t_push **stack);

// op_push //
void	ft_push(t_push **dest, t_push **src);
void	ft_pa(t_push **a, t_push **b);
void	ft_pb(t_push **b, t_push **a);

// op_swap //
void	ft_swap_a(t_push **stack_a);
void	ft_swap_b(t_push **stack_b);
void	ft_swap(t_push **stack);

// free //
void	ft_free(char **ptr_matrix, int j);
void	ft_clear_list(t_push **lst);

// main //
int		ft_validate(int *c, char **v, t_bool ent);
int		ft_check_numbers(char **str);
int		ft_check_duplicate(t_push **stack);
int		ft_is_sorted(t_push **stack);

// list_manipulation //
t_push	*ft_create_list(int count, char **v, t_bool ent);
t_push	*ft_newnode(int content);
void	ft_add_back(t_push **lst, t_push *new);
t_push	*ft_last(t_push *lst);
int		ft_listsize(t_push *lst);

// node_set_values //
void	ft_target(t_push *stack_a, t_push *stack_b);
void	ft_target_b(t_push *stack_a, t_push *stack_b);
void	ft_price(t_push *stack_a, t_push *stack_b);
void	ft_cur_position(t_push *stack);
void	ft_init_a(t_push *stack_a, t_push *stack_b);

// node_utils //
t_push	*ft_find_smallest(t_push *stack);
t_push	*ft_find_largest(t_push *stack);
t_push	*ft_find_cheapest(t_push *stack);
t_push	*ft_find_highest(t_push *stack);
void	ft_set_cheapest(t_push *stack_b);

// algorithm //
void	ft_call_algorithms(t_push **stack_a, int counter);
void	ft_manualsort_a(t_push **stack_a);
void	ft_algorithm(t_push **stack_a, t_push **stack_b);
void	ft_move(t_push **stack_a, t_push **stack_b);
void	ft_init(t_push *stack_a, t_push *stack_b);

// algorithm_utils //
void	ft_push_to_b(t_push **stack_a, t_push **stack_b);
void	ft_price_a(t_push *stack_a, t_push *stack_b);
void	ft_move_a(t_push **b, t_push **a);
int		ft_greater(int num1, int num2);
void	ft_finish_rotation(t_push **stack, t_push *cheapest, char c);

#endif /* PUSH_SWAP_H 47 Functions */