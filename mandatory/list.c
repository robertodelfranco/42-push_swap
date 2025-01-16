/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:52:04 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/15 14:26:00 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_list(int count, char **v, int ent)
{
	t_list	*new_node;
	t_list	*stack_a;
	long	nb;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < count)
	{
		nb = ft_atol(&v[i][0]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ft_clear_list(&stack_a), ft_printf("Error\n"), NULL);
		new_node = ft_lstnew((int)nb);
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	if (ent == 1)
		ft_free(v, count);
	if (!ft_check_duplicate(&stack_a))
		return (ft_clear_list(&stack_a), ft_printf("Error\n"), NULL);
	if (ft_is_sorted(&stack_a))
		return (ft_clear_list(&stack_a), NULL);
	return (stack_a);
}
