/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:42:49 by djast             #+#    #+#             */
/*   Updated: 2019/07/21 17:24:41 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int main(int argc, char const *argv[])
{
	t_stacks *stacks;
	t_commands *commands;

	stacks = init_lists();
	commands = (t_commands *) malloc(sizeof(t_commands));
	commands->data = NULL;
	commands->next = NULL;


	if (check_params(argc, argv, stacks) == CHECK_ERROR)
	{
		write(1, "ERROR\n", 6);
		return (CHECK_ERROR);
	}
	translate_to_1_N(stacks->head_a);
	//print_list("a: ", stacks->head_a);
	sorting(stacks, &commands);
	optimizate_commands(&commands, "rb", "ra", "rr");
	optimizate_commands(&commands, "sb", "sa", "ss");
	optimizate_commands(&commands, "rrb", "rra", "rrr");
	print_commands(&commands);
	return (0);
}
