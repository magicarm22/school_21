/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:36:03 by djast             #+#    #+#             */
/*   Updated: 2019/07/10 14:57:35 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void sort_3_num_ASC(t_stacks *stacks)
{
	int *seq;

	seq = sequence_1_N(stacks->head_a);
	if (seq[0] == 2 && seq[1] == 1)
		print_and_make_command(stacks, "sa");
	else if (seq[0] == 3 && seq[1] == 2)
	{
		print_and_make_command(stacks, "sa");
		print_and_make_command(stacks, "rra");
	}
	else if (seq[0] == 3 && seq[1] == 1)
		print_and_make_command(stacks, "ra");
	else if (seq[0] == 1 && seq[1] == 3)
	{
		print_and_make_command(stacks, "sa");
		print_and_make_command(stacks, "ra");
	}
	else if (seq[0] == 2 && seq[1] == 3)
		print_and_make_command(stacks, "rra");
}

static void sort_4_to_10_num(t_stacks *stacks, unsigned int list_size)
{
	int size_b;

	if (check_sort(stacks) == SORT_SUCCESS && stacks->head_b == NULL)
		return ;
	while (check_sort(stacks) != SORT_SUCCESS)
	{
		if (stacks->head_a != NULL && stacks->head_a->data == (int)list_size)
			print_and_make_command(stacks, "ra");
		else if (stacks->head_a->data == (int)size_list(stacks->head_b) + 1)
			print_and_make_command(stacks, "pb");
		else if (stacks->head_a->data > stacks->head_a->next->data)
			print_and_make_command(stacks, "sa");
		else
			print_and_make_command(stacks, "ra");
	}
	size_b = size_list(stacks->head_b);
	while (size_b-- != 0)
		print_and_make_command(stacks, "pa");
}

static void sort_many_numbers(t_stacks *stacks)
{
	(void) stacks;
}

void sorting(t_stacks *stacks)
{
	unsigned int list_size;
	
	list_size = size_list(stacks->head_a);
	if (list_size <= 3)
		sort_3_num_ASC(stacks);
	else if (list_size > 3 && list_size <= 10)
		sort_4_to_10_num(stacks, list_size);
	else
	{
		sort_many_numbers(stacks);
	}
}

/*
A: 8 --> 9 --> 6 --> 1 --> 4 --> 2 --> 3 --> 7
pb
a: 9 --> 6 --> 1 --> 4 --> 2 --> 3 --> 7
b: 8
pb
a: 6 --> 1 --> 4 --> 2 --> 3 --> 7
b: 9 --> 8
pb
a: 1 --> 4 --> 2 --> 3 --> 7
b: 6 --> 9 --> 8
rb
a: 1 --> 4 --> 2 --> 3 --> 7
b: 9 --> 8 --> 6
pb
a: 4 --> 2 --> 3 --> 7
b: 1 --> 9 --> 8 --> 6
pb
a: 2 --> 3 --> 7
b: 4 --> 1 --> 9 --> 8 --> 6
rb
a: 2 --> 3 --> 7
b: 1 --> 9 --> 8 --> 6 --> 4
pb
a: 3 --> 7
b: 2 --> 1 --> 9 --> 8 --> 6 --> 4
pb
a: 7
b: 3 --> 2 --> 1 --> 9 --> 8 --> 6 --> 4
rrb
a: 7
b: 4 --> 3 --> 2 --> 1 --> 9 --> 8 --> 6
rrb
a: 7
b: 6 --> 4 --> 3 --> 2 --> 1 --> 9 --> 8
pb
a:
b: 7 --> 6 --> 4 --> 3 --> 2 --> 1 --> 9 --> 8
rrb
a:
b: 8 --> 7 --> 6 --> 4 --> 3 --> 2 --> 1 --> 9
rrb
a:
b: 9 --> 8 --> 7 --> 6 --> 4 --> 3 --> 2 --> 1
pa
a: 9
b: 8 --> 7 --> 6 --> 4 --> 3 --> 2 --> 1
pa
a: 8 --> 9
b: 7 --> 6 --> 4 --> 3 --> 2 --> 1
pa
a: 7 --> 8 --> 9
b: 6 --> 4 --> 3 --> 2 --> 1
pa
a: 6 --> 7 --> 8 --> 9
b: 4 --> 3 --> 2 --> 1
pa
a: 4 --> 6 --> 7 --> 8 --> 9
b: 3 --> 2 --> 1
pa
a: 3 --> 4 --> 6 --> 7 --> 8 --> 9
b: 2 --> 1
pa
a: 2 --> 3 --> 4 --> 6 --> 7 --> 8 --> 9
b: 1
pa
a: 1 --> 2 --> 3 --> 4 --> 6 --> 7 --> 8 --> 9
b:
OK

*/