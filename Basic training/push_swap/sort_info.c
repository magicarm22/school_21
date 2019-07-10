/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:09:20 by djast             #+#    #+#             */
/*   Updated: 2019/07/10 12:20:59 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void set_lower_upper_info(t_sort_info *sort,
													unsigned int list_size)
{
	if (sort->lower_index < (int)list_size / 2)
	{
		sort->is_lower_above_median = 1;
		sort->lower_distance = sort->lower_index;
	}
	else
	{
		sort->is_lower_above_median = 0;
		sort->lower_distance = list_size - sort->lower_index;
	}
	if (sort->upper_index < (int)list_size / 2)
	{
		sort->is_upper_above_median = 1;
		sort->upper_distance = sort->upper_index;
	}
	else
	{
		sort->is_upper_above_median = 0;
		sort->upper_distance = list_size - sort->upper_index;
	}
	//printf("Lower_D: %d Upper_D: %d\n", sort->lower_distance, sort->upper_distance);
	if (sort->lower_distance < sort->upper_distance)
	{
		if (sort->is_lower_above_median == 1)
			sort->command = COMMAND_RA;
		else
			sort->command = COMMAND_RRA;
	}
	else
	{
		if (sort->is_upper_above_median == 1)
			sort->command = COMMAND_RA;
		else
			sort->command = COMMAND_RRA;
	}
	//printf("Command: %d\n", sort->command);
}

void get_sort_info(t_stacks *stacks, t_sort_info *sort)
{
	//printf("From: %d To: %d\n", sort->from_chunk, sort->to_chunk);
	sort->lower_index = find_elem(stacks->head_a, sort->from_chunk);
	sort->upper_index = find_elem(stacks->head_a, sort->to_chunk);
	//printf("Lower_I: %d Upper_I: %d\n", sort->lower_index, sort->upper_index);
	set_lower_upper_info(sort, size_list(stacks->head_a));
	sort->to_chunk = sort->lower_distance < sort->upper_distance ?
												sort->to_chunk :
												sort->to_chunk - 1;
	sort->from_chunk = sort->lower_distance < sort->upper_distance ?
											sort->from_chunk + 1 :
											sort->from_chunk;
}
