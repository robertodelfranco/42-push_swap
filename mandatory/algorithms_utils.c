/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:03 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/23 17:28:28 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_pivot(t_list **list, int c)
{
	int		*array;
	int		i;

	if (c == 1)
		return ((*list)->nb);
	array = ft_create_array(list, c);
	ft_bubblesort(array, c);
	i = 0;
	while (i < (c / 2))
		i++;
	return (array[i]);
}

int	ft_implement_rotate(t_list **stack_a, int pivot)
{
	t_list	*nav;

	nav = *stack_a;
	while (nav != NULL)
	{
		if (nav->nb < pivot)
			return (0);
		nav = nav->next;
	}
	return (1);
}

int ft_compare(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}
