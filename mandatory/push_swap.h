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

# include "../current_lib/Includes/libft.h"
# include "../current_lib/Includes/ft_printf_bonus.h"
# include "../current_lib/Includes/get_next_line_bonus.h"
# include "limits.h"

typedef struct s_counters
{
	int	count;
}				t_counters;

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

void	ft_reverse(t_push **stack);
void	ft_reverse_a(t_push **stack_a);
void	ft_reverse_b(t_push **stack_b);
void	ft_reverse_ss(t_push **stack_a, t_push **stack_b);
void	ft_reverse_rotate_both(t_push **stack_a, t_push **stack_b,
			t_push *cheapest);

void	ft_rotate(t_push **stack);
void	ft_rotate_a(t_push **stack_a);
void	ft_rotate_b(t_push **stack_b);
void	ft_rotate_ss(t_push **stack_a, t_push **stack_b);
void	ft_rotate_both(t_push **stack_a, t_push **stack_b, t_push *cheapest);

void	ft_push(t_push **dest, t_push **src);
void	ft_pb(t_push **b, t_push **a);
void	ft_pa(t_push **a, t_push **b);

void	ft_swap(t_push **stack);
void	ft_swap_a(t_push **stack_a);
void	ft_swap_b(t_push **stack_b);
void	ft_swap_ss(t_push **stack_a, t_push **stack_b);

int		ft_listsize(t_push *lst);
void	ft_clear_list(t_push **lst);
void	ft_free(char **ptr_matrix, int j);

int		ft_is_sorted(t_push **stack);
int		ft_check_numbers(char **str);
int		ft_reverse_sorted(t_push **stack);
int		ft_check_duplicate(t_push **stack);
int		ft_validate(int *c, char **v, int ent);

t_push	*ft_create_list(int count, char **v, int ent);
t_push	*ft_second_to_last(t_push *lst);
t_push	*ft_newnode(int content);
t_push	*ft_last(t_push *lst);
void	ft_add_back(t_push **lst, t_push *new);

void	ft_quicksort(t_push **stack_a, t_push **stack_b,
			int c, t_counters *counter);
void	ft_manualsort_a(t_push **stack_a);
void	ft_manualsort_b(t_push **stack_b, int c);
void	ft_bubblesort(int *list, int c);
t_push	*find_highest(t_push *stack);

int		ft_implement_rotate(t_push **stack_a, int pivot);
int		*ft_create_array(t_push **list, int count);
int		ft_find_pivot(t_push **list, int c);
int		ft_compare(int a, int b);

void	ft_target(t_push *stack_a, t_push *stack_b);
void	ft_price(t_push *stack_a, t_push *stack_b);
void	ft_init(t_push *stack_a, t_push *stack_b);
void	ft_cur_position(t_push *stack);
void	ft_cheapest(t_push *stack_b);

t_push	*ft_find_cheapest(t_push *stack);
t_push	*ft_find_smallest(t_push *stack);

void	ft_finish_rotation(t_push **stack, t_push *cheapest, char c);
void	ft_call_algorithms(t_push **stack_a, int counter);
void	ft_algorithm(t_push **stack_a, t_push **stack_b);
void	ft_move(t_push **stack_a, t_push **stack_b);

#endif