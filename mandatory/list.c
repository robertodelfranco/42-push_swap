/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:52:04 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/19 16:39:49 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_list(int count, char **v, int ent)
{
	t_list	*new_node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (i < count)
	{
		new_node = ft_lstnew(ft_atoi(&v[i][0]));
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	if (ent == 1)
		ft_free(v, count);
	if (!ft_check_duplicate(&stack_a))
		return (ft_clear_list(&stack_a), ft_printf("Error\n"), NULL);
	return (stack_a);
}

	// ft_push_b(&stack_a, &stack_b);
	// ft_push_b(&stack_a, &stack_b);
	// ft_push_b(&stack_a, &stack_b);
	// ft_printf("A\n");
	// t_list *nav1;
	// nav1 = stack_a;
	// while (nav1)
	// {
	// 	ft_printf("a: %d\n", nav1->nb);
	// 	nav1 = nav1->next;
	// }
	// ft_printf("\nB\n");
	// t_list *nav12;
	// nav12 = stack_b;
	// while (nav12)
	// {
	// 	ft_printf("b: %d\n", nav12->nb);
	// 	nav12 = nav12->next;
	// }
	// ft_swap_ss(&stack_a, &stack_b);
	// ft_rotate_ss(&stack_a, &stack_b);
	// ft_reverse_ss(&stack_a, &stack_b);
	// ft_printf("A\n");
	// t_list *nav2;
	// nav2 = stack_a;
	// while (nav2)
	// {
	// 	ft_printf("a: %d\n", nav2->nb);
	// 	nav2 = nav2->next;
	// }
	// ft_printf("\nB\n");
	// t_list *nav21;
	// nav21 = stack_b;
	// while (nav21)
	// {
	// 	ft_printf("b: %d\n", nav21->nb);
	// 	nav21 = nav21->next;
	// }
	// ft_push_a(&stack_b, &stack_a);
	// ft_push_a(&stack_b, &stack_a);
	// ft_push_a(&stack_b, &stack_a);
	// ft_printf("A\n");
	// t_list *nav3;
	// nav3 = stack_a;
	// while (nav3)
	// {
	// 	ft_printf("a: %d\n", nav3->nb);
	// 	nav3 = nav3->next;
	// }
	// ft_printf("\nB\n");
	// t_list *nav32;
	// nav32 = stack_b;
	// while (nav32)
	// {
	// 	ft_printf("b: %d\n", nav32->nb);
	// 	nav32 = nav32->next;
	// }
