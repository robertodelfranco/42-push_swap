/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:38:22 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/19 15:05:42 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	int	entered;

	entered = 0;
	if (c > 1)
	{
		if (c == 2)
			ft_validate(&c, ft_split(&v[1][0], ' ', &entered), entered);
		else
			ft_validate(&c, &v[1], entered);
	}
	return (0);
}
