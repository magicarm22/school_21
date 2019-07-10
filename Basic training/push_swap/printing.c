/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:03:16 by djast             #+#    #+#             */
/*   Updated: 2019/07/02 16:14:20 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void print_and_make_swap_commands(t_stacks *stacks, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
	{
		write(1, "sa\n", 3);
		stack_sa(stacks);
	}
	else if (ft_strcmp(command, "sb") == 0)
	{
		write(1, "sb\n", 3);
		stack_sb(stacks);
	}
	else if (ft_strcmp(command, "ss") == 0)
	{
		write(1, "ss\n", 3);
		stack_ss(stacks);
	}
}

static void print_and_make_push_commands(t_stacks *stacks, char *command)
{
	if (ft_strcmp(command, "pa") == 0)
	{
		write(1, "pa\n", 3);
		stack_pa(stacks);
	}
	else if (ft_strcmp(command, "pb") == 0)
	{
		write(1, "pb\n", 3);
		stack_pb(stacks);
	}
}

static void print_and_make_rotate_commands(t_stacks *stacks, char *command)
{
	if (ft_strcmp(command, "ra") == 0)
	{
		write(1, "ra\n", 3);
		stack_ra(stacks);
	}
	else if (ft_strcmp(command, "rb") == 0)
	{
		write(1, "rb\n", 3);
		stack_rb(stacks);
	}
	else if (ft_strcmp(command, "rr") == 0)
	{
		write(1, "rr\n", 3);
		stack_rr(stacks);
	}
}

static void print_and_make_reverse_rotate_commands(t_stacks *stacks,
													char *command)
{
	if (ft_strcmp(command, "rra") == 0)
	{
		write(1, "rra\n", 4);
		stack_rra(stacks);
	}
	else if (ft_strcmp(command, "rrb") == 0)
	{
		write(1, "rrb\n", 4);
		stack_rrb(stacks);
	}
	else if (ft_strcmp(command, "rrr") == 0)
	{
		write(1, "rrr\n", 4);
		stack_rrr(stacks);
	}
}

void print_and_make_command(t_stacks *stacks, char *command)
{
	if (ft_strcmp(command, "sa") == 0 || ft_strcmp(command, "sb") == 0 ||
						ft_strcmp(command, "ss") == 0)
		print_and_make_swap_commands(stacks, command);
	else if (ft_strcmp(command, "pa") == 0 || ft_strcmp(command, "pb") == 0)
		print_and_make_push_commands(stacks, command);
	else if (ft_strcmp(command, "ra") == 0 || ft_strcmp(command, "rb") == 0 ||
						ft_strcmp(command, "rr") == 0)
		print_and_make_rotate_commands(stacks, command);
	else if (ft_strcmp(command, "rra") == 0 || ft_strcmp(command, "rrb") == 0 ||
						ft_strcmp(command, "rrr") == 0)
		print_and_make_reverse_rotate_commands(stacks, command);
}

