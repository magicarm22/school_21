/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:36:03 by djast             #+#    #+#             */
/*   Updated: 2019/06/30 17:08:06 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int top(t_stack *stack)
{
	t_stack *cur_list;
	if (stack == NULL)
	{
		return (0);
	}
	cur_list = stack;
	while (cur_list->next != NULL)
		cur_list = cur_list->next;
	return cur_list->data;
}

static int check_sort_b(t_stacks *stacks)
{
	int success;
	t_stack *cur_list;
	t_stack *prev_list;

	success = 1;
	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
		return (SORT_SUCCESS);

	prev_list = stacks->head_b;
	cur_list = prev_list->next;
	while (cur_list != NULL)
	{
		if (prev_list->data < cur_list->data)
		{
			success = 0;
			break;
		}
		prev_list = cur_list;
		cur_list = cur_list->next;
	}
	if (stacks->head_a == NULL && success == 1)
		return (SORT_SUCCESS);
	else
		return (SORT_ERROR);
}

void sorting(t_stacks *stacks)
{
	
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