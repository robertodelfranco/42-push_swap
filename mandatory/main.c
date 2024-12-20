/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:38:22 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/12/20 15:55:54 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	int	ent;
	int	val;

	ent = 0;
	val = 0;
	if (c > 1)
	{
		if (c == 2)
			val = ft_validate(&c, ft_split(&v[1][0], ' ', &ent), ent);
		else
			val = ft_validate(&c, &v[1], ent);
	}
	return (0);
}
