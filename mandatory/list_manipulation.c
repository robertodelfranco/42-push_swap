/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:52:04 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 16:25:49 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_create_list(int count, char **v, int ent)
{
	t_push	*new_node;
	t_push	*stack_a;
	long	nb;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < count)
	{
		nb = ft_atol(&v[i][0]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ft_clear_list(&stack_a), ft_printf("Error\n"), NULL);
		new_node = ft_newnode((int)nb);
		ft_add_back(&stack_a, new_node);
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

t_push	*ft_newnode(int content)
{
	t_push	*new_node;

	new_node = (t_push *)malloc(sizeof(struct s_push));
	if (!new_node)
		return (NULL);
	(*new_node).nb = content;
	(*new_node).next = NULL;
	(*new_node).prev = NULL;
	(*new_node).price = 0;
	(*new_node).upper = 0;
	(*new_node).cheapest = 0;
	(*new_node).cur_position = 0;
	(*new_node).target = NULL;
	return (new_node);
}

void	ft_add_back(t_push **lst, t_push *new)
{
	t_push	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		last = ft_last(*lst);
		last->next = new;
		new->prev = last;
	}
}

t_push	*ft_second_to_last(t_push *lst)
{
	t_push	*nav;
	int		i;

	nav = lst;
	i = ft_listsize(lst);
	while (i > 2)
	{
		nav = (*nav).next;
		i--;
	}
	return (nav);
}

t_push	*ft_last(t_push *lst)
{
	t_push	*nav;
	int		i;

	nav = lst;
	i = ft_listsize(lst);
	while (i > 1)
	{
		nav = (*nav).next;
		i--;
	}
	return (nav);
}
