/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_markups.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:10:44 by djast             #+#    #+#             */
/*   Updated: 2019/07/10 17:22:46 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int set_markups(t_stack *head)
{
	t_stack *cur_list;
	int max_data;
	int count_of_markups;

	cur_list = head->next;
	max_data = head->data;
	head->markup = 1;
	count_of_markups = 1;
	while (cur_list != NULL)
	{
		if (cur_list->data > max_data)
		{
			cur_list->markup = 1;
			max_data = cur_list->data;
			count_of_markups++;
		}
		cur_list = cur_list->next;
	}
	return (count_of_markups);
}

void clear_markup(t_stack *head)
{
	t_stack *cur_list;

	cur_list = head;
	while (cur_list != NULL)
	{
		cur_list->markup = 0;
		cur_list = cur_list->next;
	}
}

int set_selected_markups(t_stack *head, int index_with_max_markups)
{
	t_stack *cur_list;
	int count_of_markups;

	cur_list = head;
	while (index_with_max_markups-- != 0)
		cur_list = cur_list->next;
	count_of_markups = set_markups(cur_list);
	return (count_of_markups);
}

int find_index_with_max_markups(t_stacks *stacks, unsigned int list_size)
{
	unsigned int cur_index;
	t_stack *cur_list;
	int max;
	int max_index;
	int cur_markups;

	cur_index = 0;
	cur_list = stacks->head_a;
	max = 0;
	max_index = 0;
	while (list_size-- != 0)
	{
		cur_markups = set_markups(cur_list);
		if (cur_markups > max)
		{
			max = cur_markups;
			max_index = cur_index;
		}
		clear_markup(cur_list);
		cur_list = cur_list->next;
		cur_index++;
	}
	return (max_index);
}