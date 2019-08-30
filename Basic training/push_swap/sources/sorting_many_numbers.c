/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_many_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 19:31:21 by djast             #+#    #+#             */
/*   Updated: 2019/08/28 20:29:43 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void					align_a(t_stacks *stacks, t_commands **commands)
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

static void				the_biggest_sequence(t_stacks *stacks,
													t_commands **commands)
{
	int index_with_max_markups;

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
}

unsigned int			choose_element(t_stacks *stacks)
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
		if (steps < min_steps)
		{
			min_steps = steps;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void					sort_many_numbers(t_stacks *stacks,
									unsigned int list_size,
									t_commands **commands)
{
	int index_with_max_markups;
	int min_index;
	int elem;

	index_with_max_markups = find_index_with_max_markups(stacks, list_size);
	set_selected_markups(stacks->head_a, index_with_max_markups);
	elem = get_elem_by_index(stacks->head_a, index_with_max_markups);
	the_biggest_sequence(stacks, commands);
	while (stacks->head_b != NULL)
	{
		min_index = choose_element(stacks);
		put_index_to_b_up(stacks, commands, min_index);
		create_place_in_a(stacks, commands);
		make_and_add_command(stacks, commands, "pa");
	}
	align_a(stacks, commands);
}
