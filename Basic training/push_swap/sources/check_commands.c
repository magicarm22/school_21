/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:20:46 by djast             #+#    #+#             */
/*   Updated: 2019/08/25 12:39:52 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	check_stack_swap(t_stacks *stacks, char command[4])
{
	if (ft_strcmp(command, "sa") == 0)
		stack_sa(stacks);
	else if (ft_strcmp(command, "sb") == 0)
		stack_sb(stacks);
	else if (ft_strcmp(command, "ss") == 0)
		stack_ss(stacks);
	else
		return (COMMAND_ERROR);
	return (COMMAND_SUCCESS);
}

static int	check_stack_push(t_stacks *stacks, char command[4])
{
	if (ft_strcmp(command, "pa") == 0)
		stack_pa(stacks);
	else if (ft_strcmp(command, "pb") == 0)
		stack_pb(stacks);
	else
		return (COMMAND_ERROR);
	return (COMMAND_SUCCESS);
}

static int	check_stack_rotate(t_stacks *stacks, char command[4])
{
	if (ft_strcmp(command, "ra") == 0)
		stack_ra(stacks);
	else if (ft_strcmp(command, "rb") == 0)
		stack_rb(stacks);
	else if (ft_strcmp(command, "rr") == 0)
		stack_rr(stacks);
	else
		return (COMMAND_ERROR);
	return (COMMAND_SUCCESS);
}

static int	check_stack_reverse_rotate(t_stacks *stacks, char command[4])
{
	if (ft_strcmp(command, "rra") == 0)
		stack_rra(stacks);
	else if (ft_strcmp(command, "rrb") == 0)
		stack_rrb(stacks);
	else if (ft_strcmp(command, "rrr") == 0)
		stack_rrr(stacks);
	else
		return (COMMAND_ERROR);
	return (COMMAND_SUCCESS);
}

int			check_commands(t_stacks *stacks, t_commands *commands)
{
	if (commands->data == NULL)
		return (COMMAND_SUCCESS);
	while (commands != NULL)
	{
		if (check_stack_swap(stacks, commands->data) == COMMAND_SUCCESS ||
			check_stack_push(stacks, commands->data) == COMMAND_SUCCESS ||
			check_stack_rotate(stacks, commands->data) == COMMAND_SUCCESS ||
			check_stack_reverse_rotate(stacks, commands->data) ==
																COMMAND_SUCCESS)
			commands = commands->next;
		else
			return (COMMAND_ERROR);
	}
	return (COMMAND_SUCCESS);
}
