/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:36:03 by djast             #+#    #+#             */
/*   Updated: 2019/07/11 13:19:13 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void sort_3_num_ASC(t_stacks *stacks)
{
	unsigned int *seq;

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

static void sort_many_numbers(t_stacks *stacks, unsigned int list_size)
{
	int index_with_max_markups;
	int min_index;
	
	//print_list("a: ", stacks->head_a);
	//print_list("b: ", stacks->head_b);
	index_with_max_markups = find_index_with_max_markups(stacks, list_size);
	set_selected_markups(stacks->head_a, index_with_max_markups);
	while (find_false_markup(stacks->head_a) != -1)
	{
		if (swap_is_needed(stacks) == 1)
		{
			print_and_make_command(stacks, "sa");
			set_markups(stacks->head_a);
		}
		else if (stacks->head_a->markup == 0)
			print_and_make_command(stacks, "pb");
		else
			print_and_make_command(stacks, "ra");
	}
	//print_list("a: ", stacks->head_a);
	//print_list("b: ", stacks->head_b);
	while (stacks->head_b != NULL)
	{
	 	min_index = choose_element(stacks);
	 	put_index_to_b_up(stacks, min_index);
	 	create_place_in_a(stacks, min_index);
	 	print_and_make_command(stacks, "pa");
	 	//print_list("a: ", stacks->head_a);
		//print_list("b: ", stacks->head_b);
	}
	align_a(stacks);
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
		sort_many_numbers(stacks, list_size);
}
