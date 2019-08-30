/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:31:58 by djast             #+#    #+#             */
/*   Updated: 2019/08/25 12:44:00 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	free_commands(t_commands *commands)
{
	t_commands *cur_command;
	t_commands *next_command;

	if (commands == NULL)
		return ;
	cur_command = commands;
	next_command = cur_command->next;
	while (cur_command != NULL)
	{
		free(cur_command->data);
		free(cur_command);
		cur_command = next_command;
		next_command = next_command->next;
	}
}

void	free_stacks(t_stacks *stacks)
{
	t_stack *cur_stack;
	t_stack *next_stack;

	cur_stack = stacks->head_a;
	if (cur_stack != NULL)
		next_stack = cur_stack->next;
	while (cur_stack != NULL)
	{
		free(cur_stack);
		cur_stack = next_stack;
		next_stack = next_stack->next;
	}
	cur_stack = stacks->head_b;
	if (cur_stack != NULL)
		next_stack = cur_stack->next;
	while (cur_stack != NULL)
	{
		free(cur_stack);
		cur_stack = next_stack;
		next_stack = next_stack->next;
	}
	free(stacks);
}
