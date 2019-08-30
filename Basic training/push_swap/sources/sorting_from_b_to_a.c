/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_from_b_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:46:46 by djast             #+#    #+#             */
/*   Updated: 2019/08/30 14:18:27 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static unsigned int		find_a_steps(t_stacks *stacks, unsigned int index)
{
	int		elem;
	t_stack	*cur_list;
	t_stack	*next_list;
	int		cur_index;

	elem = get_elem_by_index(stacks->head_b, index);
	if (stacks->head_a == NULL)
		return (0);
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
	return (0);
}

static unsigned int		find_a_steps_full(t_stacks *stacks, unsigned int index)
{
	unsigned int	a_steps;
	int				elem;

	a_steps = find_a_steps(stacks, index);
	if (a_steps == 0)
	{
		elem = get_elem_by_index(stacks->head_b, index);
		if (stacks->head_a->data > elem &&
			get_elem_by_index(stacks->head_a,
								size_list(stacks->head_a) - 1) < elem)
			a_steps = 0;
		else
			a_steps = find_min(stacks->head_a);
	}
	return (a_steps);
}

unsigned int			find_steps_from_b_to_a(t_stacks *stacks,
														unsigned int index)
{
	unsigned int	b_steps;
	unsigned int	a_steps;
	int				double_steps;
	int				status;

	b_steps = index;
	status = 0;
	if (b_steps > size_list(stacks->head_b) / 2)
	{
		status++;
		b_steps = size_list(stacks->head_b) - b_steps;
	}
	a_steps = find_a_steps_full(stacks, index);
	double_steps = 0;
	if (a_steps > size_list(stacks->head_a) / 2)
	{
		status++;
		a_steps = size_list(stacks->head_a) - a_steps;
	}
	if (status == 0 || status == 2)
		while (a_steps-- != 0 && b_steps-- != 0)
			double_steps++;
	return (b_steps + a_steps + double_steps);
}

void					put_index_to_b_up(t_stacks *stacks,
									t_commands **commands, unsigned int index)
{
	if (index > size_list(stacks->head_b) / 2)
	{
		index = size_list(stacks->head_b) - index;
		while (index-- != 0)
			make_and_add_command(stacks, commands, "rrb");
	}
	else
		while (index-- != 0)
			make_and_add_command(stacks, commands, "rb");
}

void					create_place_in_a(t_stacks *stacks,
														t_commands **commands)
{
	unsigned int	a_index;
	int				elem;

	elem = get_elem_by_index(stacks->head_b, 0);
	a_index = find_a_steps(stacks, 0);
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
