/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:29:32 by djast             #+#    #+#             */
/*   Updated: 2019/07/12 18:11:13 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void make_and_add_command(t_stacks *stacks, t_commands **commands, char *data)
{
	if (ft_strcmp(data, "sa") == 0)
		stack_sa(stacks);
	else if (ft_strcmp(data, "sb") == 0)
		stack_sb(stacks);
	else if (ft_strcmp(data, "ss") == 0)
		stack_ss(stacks);
	else if (ft_strcmp(data, "pa") == 0)
		stack_pa(stacks);
	else if (ft_strcmp(data, "pb") == 0)
		stack_pb(stacks);
	else if (ft_strcmp(data, "ra") == 0)
		stack_ra(stacks);
	else if (ft_strcmp(data, "rb") == 0)
		stack_rb(stacks);
	else if (ft_strcmp(data, "rr") == 0)
		stack_rr(stacks);
	else if (ft_strcmp(data, "rra") == 0)
		stack_rra(stacks);
	else if (ft_strcmp(data, "rrb") == 0)
		stack_rrb(stacks);
	else if (ft_strcmp(data, "rrr") == 0)
		stack_rrr(stacks);
	add_command(commands, data);
}

void add_command(t_commands **commands, char *data)
{
	t_commands *cur_command;

	if ((*commands)->data == NULL)
	{
		(*commands)->data = data;
		(*commands)->next = NULL;
		return ;
	}
	cur_command = *commands;
	//printf("%p\n", cur_command->next);
	while (cur_command->next != NULL)
		cur_command = cur_command->next;
	cur_command->next = (t_commands *) malloc(sizeof(t_commands));
	cur_command->next->data = data;
	cur_command->next->next = NULL;
}

void optimizate_commands(t_commands **commands, char *command1, char *command2,
								char *command_result)
{
	t_commands *cur_command;
	t_commands *next_command;
	t_commands *start_command;
	int count_a;
	int count_b;
	int tmp;

	cur_command = *commands;
	count_a = 0;
	count_b = 0;
	while (cur_command != NULL)
	{
		start_command = cur_command;
		while (cur_command != NULL && ft_strcmp(cur_command->data, command1) == 0)
		{
			count_b++;
			cur_command = cur_command->next;
		}
		while (cur_command != NULL && ft_strcmp(cur_command->data, command2) == 0)
		{
			count_a++;
			cur_command = cur_command->next;
		}
		while (cur_command != NULL && count_a != 0 && count_b != 0)
		{
			//printf("%d %d\n", count_a, count_b);
			tmp = count_b;
			count_b = count_b > count_a ? count_b - count_a : 0;
			count_a = tmp < count_a ? tmp : count_a;
			//printf("%d %d\n", count_a, count_b);
			while (count_b != 0)
			{
				start_command = start_command->next;
				count_b--;
			}
			while (count_a != 0)
			{
				//printf("AAA\n");
				next_command = start_command->next;
				start_command->next = next_command->next;
				start_command->data = command_result;
				free(next_command);
				start_command = start_command->next;
				count_a--;
			}
		}
		count_a = 0;
		count_b = 0;
		if (cur_command != NULL)
			cur_command = cur_command->next;
	}
}

void print_commands(t_commands **commands)
{
	t_commands *cur_command;

	cur_command = *commands;
	//printf("%p\n", cur_command);
	while (cur_command != NULL)
	{
		if (ft_strcmp(cur_command->data, "rra") == 0 ||
			ft_strcmp(cur_command->data, "rrb") == 0 ||
			ft_strcmp(cur_command->data, "rrr") == 0)
			write(1, cur_command->data, 3);
		else
			write(1, cur_command->data, 2);
		write(1, "\n", 1);
		cur_command = cur_command->next;
	}
}