/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:00:49 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/20 15:59:22 by rdel-fra         ###   ########.fr       */
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

	nav = NULL;
	while (*lst != NULL)
	{
		nav = (*lst)->next;
		free(*lst);
		*lst = nav;
	}
}
