/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:43:00 by djast             #+#    #+#             */
/*   Updated: 2019/08/28 16:16:08 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	read_commands(t_commands **commands)
{
	int		read_bytes;
	char	*line;

	while ((read_bytes = get_next_line(0, &line)) == 1)
	{
		add_command(commands, ft_strdup(line));
		free(line);
	}
	return (COMMAND_SUCCESS);
}

static int	next_step_checker(t_stacks *stacks, t_commands *commands)
{
	if (check_commands(stacks, commands) == CHECK_ERROR)
	{
		free_commands(commands);
		free_stacks(stacks);
		write(1, "Error\n", 6);
		return (CHECK_ERROR);
	}
	if (check_sort(stacks) == SORT_ERROR || stacks->head_b != NULL)
	{
		free_commands(commands);
		free_stacks(stacks);
		write(1, "KO\n", 3);
		return (SORT_ERROR);
	}
	return (SORT_SUCCESS);
}

int			main(int argc, char const *argv[])
{
	t_stacks	*stacks;
	t_commands	*commands;

	if (argc == 1)
		return (0);
	stacks = init_lists();
	commands = (t_commands *)malloc(sizeof(t_commands));
	commands->data = NULL;
	commands->next = NULL;
	if (check_params(argc, argv, stacks) == CHECK_ERROR)
	{
		free_stacks(stacks);
		write(1, "Error\n", 6);
		return (CHECK_ERROR);
	}
	read_commands(&commands);
	if (next_step_checker(stacks, commands) == -1)
		return (-1);
	write(1, "OK\n", 3);
	free_commands(commands);
	free_stacks(stacks);
	return (SORT_SUCCESS);
}
