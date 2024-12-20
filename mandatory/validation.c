/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:58:59 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/20 16:18:58 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!ft_check_numbers(v) && ent == 1)
		return (ft_free(v, count), ft_printf("Error\n"), 0);
	else if (!ft_check_numbers(v))
		return (ft_printf("Error\n"), 0);
	start = ft_create_list(count, v, ent);
	if (!start)
		return (0);
	ft_call_algorithm(&start, count);
	return (1);
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
			if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
				j++;
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicate(t_list **stack)
{
	t_list	*current;
	t_list	*nav;
	int		value;

	current = *stack;
	while (current != NULL)
	{
		value = current->nb;
		nav = current->next;
		while (nav != NULL)
		{
			if (nav->nb == value)
				return (0);
			nav = nav->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_is_sorted(t_list **stack)
{
	t_list	*nav;

	nav = *stack;
	while (nav->next != NULL)
	{
		if (nav->next != NULL && nav->nb > nav->next->nb)
			return (0);
		nav = nav->next;
	}
	return (1);
}
