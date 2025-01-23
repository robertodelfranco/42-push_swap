/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:13:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/23 13:17:52 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../current_lib/Includes/libft.h"
# include "../current_lib/Includes/ft_printf_bonus.h"
# include "../current_lib/Includes/get_next_line_bonus.h"

# define EXIT_NO_ARGS -1
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_stack
{
	int				nb;
	int				pos;
	int				cost;
	t_bool			above_center;
	t_bool			lcost;
	struct s_stack	*match_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}t_stack;

typedef struct s_push
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_bool		check_argv;
	char		**argv;
	size_t		length_a;
	size_t		length_b;
}t_push;

typedef enum e_mv
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}t_mv;

typedef enum e_name
{
	a,
	b
}t_name;

// Init Functions
t_push	*init_push_swap(int argc, char *argv[]);
void	init_stacks(t_push *push_swap);
void	link_node(t_stack **stack, int nb);

// Validate Functions
void	validate_args(t_push *push_swap);
t_bool	check_duplication(char *args_list[]);
t_bool	check_letters(char *nbr);

// Node Functions
t_stack	*create_node(int value);
t_stack	*find_last_node(t_stack *stack);

// Stack Functions
t_bool	check_ordered(t_stack *stack);
size_t	stack_length(t_stack *stack);
void	free_stack(t_stack **stack);
int		ft_isatty(int fd);
void	set_position(t_stack *stack);

// Error Functions
void	message_error(short error_code);
void	free_and_close(t_push *push_swap, short exit_code);
void	clear_invalid_movment(t_push *push_swap, char *command);
void	free_split_list(char **split_list);

// Checker Functions
void	read_commands(t_push *push_swap);
void	execute_commands(t_push *push_swap, char *command);
void	verify_stack(t_push *push_swap);

// Command Functions
void	push(t_push *push_swap, t_mv type, t_bool print_checker);
void	execute_push(t_stack **dst_stack, t_stack **src_stack);
void	swap(t_push *push_swap, t_mv type, t_bool print_checker);
void	execute_swap(t_stack **stack);
void	rotate(t_push *push_swap, t_mv type, t_bool print_checker);
void	execute_rotate(t_stack **stack);
void	reverse_rotate(t_push *push_swap, t_mv type, t_bool print_checker);
void	execute_rev_rot(t_stack **stack);

#endif