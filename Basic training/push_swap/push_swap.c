/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:42:49 by djast             #+#    #+#             */
/*   Updated: 2019/07/16 15:48:52 by djast            ###   ########.fr       */
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
	sorting(stacks, &commands);
	//print_commands(&commands);
	optimizate_commands(&commands, "rb", "ra", "rr");
	optimizate_commands(&commands, "sb", "sa", "ss");
	optimizate_commands(&commands, "rrb", "rra", "rrr");
	print_commands(&commands);

	// start_tests(stacks);

	// print_list("a: ", stacks->head_a);
	// print_list("b: ", stacks->head_b);
	// stack_ra(stacks);
	// write(1, "ra\n", 3);
	// print_list("a: ", stacks->head_a);
	// print_list("b: ", stacks->head_b);
	// stack_pb(stacks);
	// write(1, "pb\n", 3);
	// print_list("a: ", stacks->head_a);
	// print_list("b: ", stacks->head_b);
	// stack_pb(stacks);
	// write(1, "pb\n", 3);
	// print_list("a: ", stacks->head_a);
	// print_list("b: ", stacks->head_b);
	// stack_pb(stacks);
	// write(1, "pb\n", 3);
	// print_list("a: ", stacks->head_a);
	// print_list("b: ", stacks->head_b);
	// stack_rrb(stacks);
	// write(1, "rrb\n", 4);
	// print_list("a: ", stacks->head_a);
	// print_list("b: ", stacks->head_b);
	// stack_rrr(stacks);
	// write(1, "rrr\n", 4);
	// print_list("a: ", stacks->head_a);
	// print_list("b: ", stacks->head_b);


	return (0);
}
