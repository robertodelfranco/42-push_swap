/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:22:52 by rheringe          #+#    #+#             */
/*   Updated: 2025/03/24 19:25:21 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_push	*push_swap;

	if (argc == 1)
		message_error(EXIT_SUCCESS);
	else
	{
		push_swap = init_push_swap(argc, argv);
		printf("sizeof pointer to t_push: %lu\n", sizeof(t_push *));
		printf("sizeof t_push: %lu\n", sizeof(t_push));
		printf("sizeof t_stack: %lu\n", sizeof(t_stack));
		validate_args(push_swap);
		init_stacks(push_swap);
		read_commands(push_swap);
		verify_stack(push_swap);
		free_and_close(push_swap, EXIT_SUCCESS);
	}
	return (0);
}
