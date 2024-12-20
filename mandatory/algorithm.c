/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:18:23 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/20 16:20:48 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_algorithm(t_list **stack, int counter)
{
	if (counter < 4)
		ft_manualsort(stack, counter);
	else if (counter >= 4 && counter <= 100)
		ft_quicksort(stack, counter);
	else
		ft_radixsort(stack, counter);
}