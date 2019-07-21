/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:36:03 by djast             #+#    #+#             */
/*   Updated: 2019/07/21 17:24:49 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void sort_3_num_ASC(t_stacks *stacks, t_commands **commands)
{
	t_stack *cur_list;

	cur_list = stacks->head_a;
	if (cur_list->data == 2 && cur_list->next->data == 1)
		make_and_add_command(stacks, commands, "sa");
	else if (cur_list->data == 3 && cur_list->next->data == 2)
	{
		make_and_add_command(stacks, commands, "sa");
		make_and_add_command(stacks, commands, "rra");
	}
	else if (cur_list->data == 3 && cur_list->next->data == 1)
			make_and_add_command(stacks, commands, "ra");
	else if (cur_list->data == 1 && cur_list->next->data == 3)
	{
		make_and_add_command(stacks, commands, "sa");
		make_and_add_command(stacks, commands, "ra");
	}
	else if (cur_list->data == 2 && cur_list->next->data == 3)
	{
		make_and_add_command(stacks, commands, "rra");
	}
}

static void sort_4_to_10_num(t_stacks *stacks, unsigned int list_size, 
													t_commands **commands)
{
	int size_b;

	if (check_sort(stacks) == SORT_SUCCESS)
		return ;
	while (check_sort(stacks) != SORT_SUCCESS)
	{
		if (stacks->head_a != NULL && size_list(stacks->head_a) > 2 && stacks->head_a->data == (int)list_size)
			make_and_add_command(stacks, commands, "ra");
		else if (stacks->head_a != NULL && stacks->head_a->data == (int)size_list(stacks->head_b) + 1)
			make_and_add_command(stacks, commands, "pb");
		else if (stacks->head_a != NULL && stacks->head_a->data > stacks->head_a->next->data)
			make_and_add_command(stacks, commands, "sa");
		else
			make_and_add_command(stacks, commands, "ra");
	}
	size_b = size_list(stacks->head_b);
	while (size_b-- != 0)
		make_and_add_command(stacks, commands, "pa");
}

static void sort_many_numbers(t_stacks *stacks, unsigned int list_size,
														t_commands **commands)
{
	int index_with_max_markups;
	int min_index;
	int elem;
	
	index_with_max_markups = find_index_with_max_markups(stacks, list_size);
	set_selected_markups(stacks->head_a, index_with_max_markups);
	elem = get_elem_by_index(stacks->head_a, index_with_max_markups);
	while (find_false_markup(stacks->head_a) != -1)
	{
		if ((index_with_max_markups = swap_is_needed(stacks)) != 0)
		{
			make_and_add_command(stacks, commands, "sa");
			clear_markup(stacks->head_a);
			set_selected_markups(stacks->head_a, index_with_max_markups);
		}
		else if (stacks->head_a->markup == 0)
			make_and_add_command(stacks, commands, "pb");
		else
			make_and_add_command(stacks, commands, "ra");
	}
	while (stacks->head_b != NULL)
	{
	 	min_index = choose_element(stacks);
	 	put_index_to_b_up(stacks, commands, min_index);
	 	create_place_in_a(stacks, commands);
	 	make_and_add_command(stacks, commands, "pa");
	}
	align_a(stacks, commands);
}

void sorting(t_stacks *stacks, t_commands **commands)
{
	unsigned int list_size;

	list_size = size_list(stacks->head_a);
	if (list_size <= 3)
		sort_3_num_ASC(stacks, commands);
	else if (list_size > 3 && list_size <= 9)
	 	sort_4_to_10_num(stacks, list_size, commands);
	else
		sort_many_numbers(stacks, list_size, commands);
	}
