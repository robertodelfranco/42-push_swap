/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:58:59 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:39:13 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	int	ent;

	ent = 0;
	if (c > 1)
	{
		if (c == 2)
			ft_validate(&c, ft_split(&v[1][0], ' ', &ent), ent);
		else
			ft_validate(&c, &v[1], ent);
	}
	return (0);
}

int	ft_validate(int *c, char **v, int ent)
{
	t_push	*start;
	int		count;

	start = NULL;
	*c = ft_ptrlen(v);
	count = *c;
	if (!ft_check_numbers(v) && ent == 1)
		return (ft_free(v, count), write(2, "Error\n", 6), 0);
	if (!ft_check_numbers(v))
		return (write(2, "Error\n", 6), 0);
	start = ft_create_list(count, v, ent);
	if (!start)
		return (0);
	ft_call_algorithms(&start, count);
	ft_clear_list(&start);
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

int	ft_check_duplicate(t_push **stack)
{
	t_push	*current;
	t_push	*nav;
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

int	ft_is_sorted(t_push **stack)
{
	t_push	*nav;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	nav = *stack;
	while (nav->next != NULL)
	{
		if (nav->nb > nav->next->nb)
			return (0);
		nav = nav->next;
	}
	return (1);
}
