/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:42:49 by djast             #+#    #+#             */
/*   Updated: 2019/06/24 17:49:11 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void start_tests(t_stacks *stacks)
{
	add_list_to_back(&stacks->head_a, 3);
	add_list_to_back(&stacks->head_a, 5);
	add_list_to_back(&stacks->head_a, 8);

	add_list_to_back(&stacks->head_b, 12);
	add_list_to_back(&stacks->head_b, 22);
	add_list_to_back(&stacks->head_b, 23);
}

int main()
{
	t_stacks *stacks;

	stacks = init_lists();

	start_tests(stacks);

	print_list("a: ", stacks->head_a);
	print_list("b: ", stacks->head_b);
	stack_ra(stacks);
	write(1, "ra\n", 3);
	print_list("a: ", stacks->head_a);
	print_list("b: ", stacks->head_b);
	stack_pb(stacks);
	write(1, "pb\n", 3);
	print_list("a: ", stacks->head_a);
	print_list("b: ", stacks->head_b);
	stack_pb(stacks);
	write(1, "pb\n", 3);
	print_list("a: ", stacks->head_a);
	print_list("b: ", stacks->head_b);
	stack_pb(stacks);
	write(1, "pb\n", 3);
	print_list("a: ", stacks->head_a);
	print_list("b: ", stacks->head_b);
	stack_rrb(stacks);
	write(1, "rrb\n", 4);
	print_list("a: ", stacks->head_a);
	print_list("b: ", stacks->head_b);
	stack_rrr(stacks);
	write(1, "rrr\n", 4);
	print_list("a: ", stacks->head_a);
	print_list("b: ", stacks->head_b);
	return (0);
}
