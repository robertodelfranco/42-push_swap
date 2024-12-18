/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:38:22 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 17:09:52 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../current_lib/Includes/libft.h"
#include "../current_lib/Includes/ft_printf_bonus.h"
#include "../current_lib/Includes/get_next_line_bonus.h"

//	movement sa
//	movement sb
//	movement ss

//	movement pa
//	movement pb

//	movement ra
//	movement rb
//	movement rr

//	movement rra
//	movement rrb
//	movement rrr

// functions read, write, malloc, free, exit

// ft_printf and any equivalent YOU coded

void	ft_rotate(t_list **stack)
{
	t_list	*start;
	t_list	*last;

	start = *stack;
	last = ft_lstlast(*stack);
	*stack = start->next;
	last->next = start;
	start->next = NULL;
}

void	ft_swap(t_list **stack)
{
	t_list	*start;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	start = *stack;
	second = (*stack)->next;
	start->next = second->next;
	second->next = start;
	*stack = second;
}

void ft_push(t_list **push, t_list **stack)
{
	t_list	*push_start;
	t_list	*stack_start;

	push_start = *push;
	stack_start = *stack;
	*stack = stack_start->next;
	stack_start->next = push_start;
	*push = stack_start;
}

t_list	*ft_create_list(int count, char **v)
{
	t_list	*new_node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < count)
	{
		new_node = ft_lstnew(ft_atoi(&v[i][0]));
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	stack_b = NULL;
	ft_push(&stack_b, &stack_a);
	t_list *nav;
	nav = stack_a;
	while (nav)
	{
		ft_printf("a: %d\n", nav->nb);
		nav = nav->next;
	}
	ft_printf("b: %d\n", stack_b->nb);
	//ft_check_duplicate(stack_a);
	return (stack_a);
}

	// ft_swap(&stack_a);
	// ft_rotate(&stack_a);

void	ft_free(char **ptr_matrix, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(ptr_matrix[i]);
		i++;
	}
	free(ptr_matrix);
}

int	ft_check_numbers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;	
		while (str[i][j] != '\0')
		{
			if (j == 0 && str[i][j] == '-')
				j++;
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_validate(int *c, char **v, int ent)
{
	t_list	*start;
	int		count;

	start = NULL;
	*c = ft_ptrlen(v);
	count = *c;
	if (count == 1 && ent == 1)
		return (ft_free(v, count), ft_printf("Error split\n"), 0);
	if (count == 1)
		return (ft_printf("Error\n"), 0);
	if (!ft_check_numbers(v))
		return (ft_printf("Error\n"), 0);
	start = ft_create_list(count, v);
	if (!start)
		return (ft_printf("start null"), 0);
	return (1);
}

int	main(int c, char **v)
{
	int	entered;
	int	val;

	entered = 0;
	val = 0;
	if (c > 1)
	{
		if (c == 2)
			val = ft_validate(&c, ft_split(&v[1][0], ' ', &entered), entered);
		else
			val = ft_validate(&c, &v[1], entered);
	}
	return (0);
}
