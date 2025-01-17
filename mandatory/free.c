/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:00:49 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/01/17 09:10:33 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_clear_list(t_push **lst)
{
	t_push	*nav;
	t_push	*tmp;

	if (!lst)
		return ;
	nav = *lst;
	while (nav)
	{
		tmp = nav->next;
		free(nav);
		nav = tmp;
	}
	*lst = NULL;
}

int	ft_listsize(t_push *lst)
{
	t_push	*ptr;
	int		i;

	i = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
