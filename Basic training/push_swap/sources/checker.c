/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:43:00 by djast             #+#    #+#             */
/*   Updated: 2019/07/21 17:27:56 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int read_commands(t_stacks *stacks)
{
	int read_bytes;
	char *line;

	while ((read_bytes = get_next_line(0, &line)) != 0)
	{

		if (check_commands(stacks, line) == COMMAND_ERROR)
			return (COMMAND_ERROR);
		free(line);
	}
	return (COMMAND_SUCCESS);
}

int main(int argc, char const *argv[])
{
	t_stacks *stacks;

	if (argc == 1)
		return 0;
	stacks = init_lists();
	if (check_params(argc, argv, stacks) == CHECK_ERROR || 
		read_commands(stacks) == COMMAND_ERROR)
	{
		write(1, "Error\n", 6);
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