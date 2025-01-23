/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:05:17 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/23 13:33:12 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	read_commands(t_push *push_swap)
{
	char	*command;

	while (TRUE)
	{
		command = get_next_line(STDIN_FILENO);
		if (command == NULL)
			break ;
		execute_commands(push_swap, command);
		free(command);
	}
}

void	execute_commands(t_push *push_swap, char *command)
{
	if (!ft_strncmp(command, "sa\n", 3))
		swap(push_swap, sa, FALSE);
	else if (!ft_strncmp(command, "sb\n", 3))
		swap(push_swap, sb, FALSE);
	else if (!ft_strncmp(command, "ss\n", 3))
		swap(push_swap, ss, FALSE);
	else if (!ft_strncmp(command, "pa\n", 3))
		push(push_swap, pa, FALSE);
	else if (!ft_strncmp(command, "pb\n", 3))
		push(push_swap, pb, FALSE);
	else if (!ft_strncmp(command, "ra\n", 3))
		rotate(push_swap, ra, FALSE);
	else if (!ft_strncmp(command, "rb\n", 3))
		rotate(push_swap, rb, FALSE);
	else if (!ft_strncmp(command, "rr\n", 3))
		rotate(push_swap, rr, FALSE);
	else if (!ft_strncmp(command, "rra\n", 4))
		reverse_rotate(push_swap, rra, FALSE);
	else if (!ft_strncmp(command, "rrb\n", 4))
		reverse_rotate(push_swap, rrb, FALSE);
	else if (!ft_strncmp(command, "rrr\n", 4))
		reverse_rotate(push_swap, rrr, FALSE);
	else
		clear_invalid_movment(push_swap, command);
}

void	verify_stack(t_push *push_swap)
{
	size_t	length;

	length = stack_length(push_swap->stack_a);
	if ((check_ordered(push_swap->stack_a)) && \
		(length == push_swap->length_a) && \
		(push_swap->stack_b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	ft_isatty(int fd)
{
	return (write(fd, "\0", 1) == 1);
}
