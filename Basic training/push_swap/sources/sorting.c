/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:36:03 by djast             #+#    #+#             */
/*   Updated: 2019/08/28 20:16:52 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void		sort_3_num(t_stacks *stacks, t_commands **commands)
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

static void		sort_4_to_10_num(t_stacks *stacks, unsigned int list_size,
													t_commands **commands)
{
	int size_b;

	if (check_sort(stacks) == SORT_SUCCESS)
		return ;
	while (check_sort(stacks) != SORT_SUCCESS)
	{
		if (stacks->head_a != NULL && size_list(stacks->head_a) > 2 &&
										stacks->head_a->data == (int)list_size)
			make_and_add_command(stacks, commands, "ra");
		else if (stacks->head_a != NULL && stacks->head_a->data ==
											(int)size_list(stacks->head_b) + 1)
			make_and_add_command(stacks, commands, "pb");
		else if (stacks->head_a != NULL && stacks->head_a->data >
												stacks->head_a->next->data)
			make_and_add_command(stacks, commands, "sa");
		else
			make_and_add_command(stacks, commands, "ra");
	}
	size_b = size_list(stacks->head_b);
	while (size_b-- != 0)
		make_and_add_command(stacks, commands, "pa");
}

void			sorting(t_stacks *stacks, t_commands **commands)
{
	unsigned int list_size;

	list_size = size_list(stacks->head_a);
	if (list_size == 1)
		return ;
	if (list_size <= 3)
		sort_3_num(stacks, commands);
	else if (list_size > 3 && list_size <= 9)
		sort_4_to_10_num(stacks, list_size, commands);
	else
		sort_many_numbers(stacks, list_size, commands);
}
