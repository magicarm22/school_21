/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_from_b_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:46:46 by djast             #+#    #+#             */
/*   Updated: 2019/07/11 13:26:45 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"


static unsigned int find_a_steps(t_stacks *stacks, unsigned int index)
{
	int elem;
	t_stack *cur_list;
	t_stack *next_list;
	int cur_index;

	elem = get_elem_by_index(stacks->head_b, index);
	//printf("elem: %d\n", elem);
	if (stacks->head_a == NULL)
		return 0;
	cur_list = stacks->head_a;
	next_list = stacks->head_a->next;
	cur_index = 1;
	while (next_list != NULL)
	{
		if (cur_list->data < elem && next_list->data > elem)
			return (cur_index);
		cur_index++;
		next_list = next_list->next;
		cur_list = cur_list->next;
	}
	return 0;
}

static unsigned int find_b_steps(t_stacks *stacks, unsigned int index)
{
	if (index > size_list(stacks->head_b) / 2)
		return size_list(stacks->head_b) - index;
	else
		return index;
}

static unsigned int find_steps_from_b_to_a(t_stacks *stacks, unsigned int index)
{
	(void) stacks;
	unsigned int b_steps;
	unsigned int a_steps;

	b_steps = find_b_steps(stacks, index);
	//printf("B: %d\n", b_steps);
	a_steps = find_a_steps(stacks, index);
	if (a_steps == 0)
		a_steps = find_min(stacks->head_a);
	else if (a_steps > size_list(stacks->head_a) / 2)
		a_steps = size_list(stacks->head_a) - a_steps;
	//printf("A: %d\n", a_steps);
	return b_steps + a_steps;
}

unsigned int choose_element(t_stacks *stacks)
{
	unsigned int i;
	unsigned int steps;
	unsigned int min_steps;
	unsigned int min_index;

	i = 0;
	min_steps = 0;
	min_index = 0;
	while (i != size_list(stacks->head_b))
	{
		steps = find_steps_from_b_to_a(stacks, i);
		if (steps < min_steps)
		{
			min_steps = steps;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void put_index_to_b_up(t_stacks *stacks, unsigned int index)
{
	if (index > size_list(stacks->head_b) / 2)
	{
		//printf("index: %d, size: %d\n", index, size_list(stacks->head_b));
		index = size_list(stacks->head_b) - index;
		while (index-- != 0)
			print_and_make_command(stacks, "rrb");
	}
	else
		while (index-- != 0)
			print_and_make_command(stacks, "rb");
	//print_list("B: ", stacks->head_b);
}

void create_place_in_a(t_stacks *stacks, unsigned int index)
{
	unsigned int a_index;

	a_index = find_a_steps(stacks, index);
	if (a_index == 0)
		a_index = find_min(stacks->head_a);
	if (a_index > size_list(stacks->head_a) / 2)
	{
		a_index = size_list(stacks->head_a) - a_index;
		while (a_index-- != 0)
			print_and_make_command(stacks, "rra");
	}
	else
		while (a_index-- != 0)
			print_and_make_command(stacks, "ra");
}

void align_a(t_stacks *stacks)
{
	unsigned int index_min_elem;

	index_min_elem = find_min(stacks->head_a);
	if (index_min_elem > size_list(stacks->head_a) / 2)
	{
		index_min_elem = size_list(stacks->head_a) - index_min_elem;
		while (index_min_elem-- != 0)
			print_and_make_command(stacks, "rra");
	}
	else
		while (index_min_elem-- != 0)
			print_and_make_command(stacks, "ra");
}

