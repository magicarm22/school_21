/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_markups.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:10:44 by djast             #+#    #+#             */
/*   Updated: 2019/08/30 14:18:33 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int		set_markup_from_start(t_stack *start, t_stack *markup_list,
											int max_data)
{
	t_stack		*cur_list;
	int			count_of_markups;

	count_of_markups = 0;
	cur_list = start;
	while (cur_list != markup_list)
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

int				set_markups(t_stack *start, t_stack *markup_list)
{
	t_stack		*cur_list;
	int			max_data;
	int			count_of_markups;

	cur_list = markup_list->next;
	max_data = markup_list->data;
	markup_list->markup = 1;
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
	count_of_markups += set_markup_from_start(start, markup_list, max_data);
	return (count_of_markups);
}

void			clear_markup(t_stack *head)
{
	t_stack *cur_list;

	cur_list = head;
	while (cur_list != NULL)
	{
		cur_list->markup = 0;
		cur_list = cur_list->next;
	}
}

int				set_selected_markups(t_stack *head, int index_with_max_markups)
{
	t_stack		*cur_list;
	int			count_of_markups;

	cur_list = head;
	while (index_with_max_markups-- != 0)
		cur_list = cur_list->next;
	count_of_markups = set_markups(head, cur_list);
	return (count_of_markups);
}

int				find_index_with_max_markups(t_stacks *stacks,
													unsigned int list_size)
{
	unsigned int	cur_index;
	t_stack			*cur_list;
	int				max;
	int				max_index;
	int				cur_markups;

	cur_index = 0;
	cur_list = stacks->head_a;
	max = 0;
	max_index = 0;
	while (list_size-- != 0)
	{
		cur_markups = set_markups(stacks->head_a, cur_list);
		if (cur_markups > max)
		{
			max = cur_markups;
			max_index = cur_index;
		}
		clear_markup(stacks->head_a);
		cur_list = cur_list->next;
		cur_index++;
	}
	return (max_index);
}
