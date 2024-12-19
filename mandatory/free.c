/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:00:49 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/19 16:25:58 by rdel-fra         ###   ########.fr       */
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

void	ft_clear_list(t_list **lst)
{
	t_list *nav;

	nav = NULL;
	while (nav != NULL)
	{
		nav = (*lst)->next;
		free(*lst);
		*lst = nav;
	}
}