/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:43:00 by djast             #+#    #+#             */
/*   Updated: 2019/07/04 14:58:42 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"


static int read_commands(t_stacks *stacks)
{
	int read_bytes;
	char *command;

	command = (char *)malloc(sizeof(char) * COMMAND_SIZE);

	while ((read_bytes = read(0, command, COMMAND_SIZE)) != 0)
	{
		if (ft_strchr(command, '\n') != NULL)
		{
			command[ft_strchr(command, '\n') - command] = '\0';
			if (check_commands(stacks, command) == COMMAND_ERROR)
				return (COMMAND_ERROR);
		}
		else
			return (COMMAND_ERROR);
	}
	return (COMMAND_SUCCESS);
}

int main(int argc, char const *argv[])
{
	t_stacks *stacks;

	stacks = init_lists();
	if (check_params(argc, argv, stacks) == CHECK_ERROR || 
		read_commands(stacks) == COMMAND_ERROR)
	{
		write(1, "ERROR\n", 6);
		return (CHECK_ERROR);
	}
	if (check_sort(stacks) == SORT_ERROR || stacks->head_b != NULL)
	{
		write(1, "KO\n", 3);
		return (SORT_ERROR);
	}
	else
	{
		write(1, "OK\n", 3);
		return (SORT_SUCCESS);
	}
}