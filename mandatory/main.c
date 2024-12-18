/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:38:22 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/18 18:12:37 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
