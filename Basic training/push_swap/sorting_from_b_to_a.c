/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_from_b_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:46:46 by djast             #+#    #+#             */
/*   Updated: 2019/07/16 18:45:15 by djast            ###   ########.fr       */
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

static unsigned int find_steps_from_b_to_a(t_stacks *stacks, unsigned int index)
{
	unsigned int b_steps;
	unsigned int a_steps;
	int elem;
	int double_steps;
	int status;

	b_steps = index;
	status = 0;
	if (b_steps > size_list(stacks->head_b) / 2)
	{
		status++;
		b_steps = size_list(stacks->head_b) - b_steps;
	}
	//printf("B: %d\n", b_steps);
	a_steps = find_a_steps(stacks, index);
	//printf("A_before: %d\n", a_steps);
	if (a_steps == 0)
	{
		elem = get_elem_by_index(stacks->head_b, index);
		if (stacks->head_a->data > elem && 
			get_elem_by_index(stacks->head_b, size_list(stacks->head_b) - 1) < elem)
			a_steps = 0;
		else
			a_steps = find_min(stacks->head_a);
	}
	double_steps = 0;
	if (a_steps > size_list(stacks->head_a) / 2)
	{
		status++;
		a_steps = size_list(stacks->head_a) - a_steps;
	}
	if (status == 0 || status == 2)
		while (a_steps != 0 && b_steps != 0)
		{
			a_steps--;
			b_steps--;
			double_steps++;
		}
	//printf("b_steps: %d, a_steps: %d, double_steps: %d\n", a_steps, b_steps, double_steps);
	return b_steps + a_steps + double_steps;
}

unsigned int choose_element(t_stacks *stacks)
{
	unsigned int i;
	unsigned int steps;
	unsigned int min_steps;
	unsigned int min_index;

	i = 0;
	min_steps = INT_MAX;
	min_index = 0;
	while (i != size_list(stacks->head_b))
	{
		steps = find_steps_from_b_to_a(stacks, i);
		//printf("steps: %u, min_steps: %u, elem: %d\n", steps, min_steps, get_elem_by_index(stacks->head_b, i));
		if (steps < min_steps)
		{
			min_steps = steps;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void put_index_to_b_up(t_stacks *stacks, t_commands **commands, unsigned int index)
{
	//printf("choose_index: %d\n", index);
	if (index > size_list(stacks->head_b) / 2)
	{
		//printf("index: %d, size: %d\n", index, size_list(stacks->head_b));
		index = size_list(stacks->head_b) - index;
		while (index-- != 0)
			make_and_add_command(stacks, commands, "rrb");
	}
	else
		while (index-- != 0)
			make_and_add_command(stacks, commands, "rb");
	//print_list("B: ", stacks->head_b);
}

void create_place_in_a(t_stacks *stacks, t_commands **commands)
{
	unsigned int a_index;
	int elem;

	//printf("index: %d", index);
	elem = get_elem_by_index(stacks->head_b, 0);
	a_index = find_a_steps(stacks, 0);
	//printf("a_index: %d\n", a_index);
	if (a_index == 0)
	{
		if (stacks->head_a->data > elem && get_last_elem(stacks->head_a) < elem)
			return ;
		a_index = find_min(stacks->head_a);
	}

	if (a_index > size_list(stacks->head_a) / 2)
	{
		a_index = size_list(stacks->head_a) - a_index;
		while (a_index-- != 0)
			make_and_add_command(stacks, commands, "rra");
	}
	else
		while (a_index-- != 0)
			make_and_add_command(stacks, commands, "ra");
}

void align_a(t_stacks *stacks, t_commands **commands)
{
	unsigned int index_min_elem;


	index_min_elem = find_min(stacks->head_a);
	if (index_min_elem > size_list(stacks->head_a) / 2)
	{
		index_min_elem = size_list(stacks->head_a) - index_min_elem;
		while (index_min_elem-- != 0)
			make_and_add_command(stacks, commands, "rra");
	}
	else
		while (index_min_elem-- != 0)
			make_and_add_command(stacks, commands, "ra");
}

