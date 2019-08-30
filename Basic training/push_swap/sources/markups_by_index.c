/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markups_by_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:23:54 by djast             #+#    #+#             */
/*   Updated: 2019/08/25 12:46:10 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int		set_markups_by_index(t_stack *head, unsigned int cur_index)
{
	t_stack		*cur_list;
	int			count_of_markups;
	int			i;

	i = 0;
	cur_list = head;
	count_of_markups = 0;
	while (cur_list->data != (int)cur_index && cur_list != NULL)
		cur_list = cur_list->next;
	if (cur_list != NULL)
		cur_list = cur_list->next;
	while (cur_list != NULL)
	{
		if (cur_list->data == (int)cur_index + 1)
		{
			cur_list->markup = 1;
			count_of_markups++;
			cur_index++;
		}
		cur_list = cur_list->next;
	}
	return (count_of_markups);
}

int		find_index_with_max_markups_by_index(t_stacks *stacks,
												unsigned int list_size)
{
	unsigned int	cur_index;
	t_stack			*cur_list;
	int				max;
	int				max_index;
	int				cur_markups;

	cur_index = 1;
	cur_list = stacks->head_a;
	max = 0;
	max_index = 0;
	while (list_size-- != 0)
	{
		cur_markups = set_markups_by_index(stacks->head_a, cur_index);
		if (cur_markups > max)
		{
			max = cur_markups;
			max_index = cur_index;
		}
		clear_markup(cur_list);
		cur_index++;
	}
	return (max_index);
}
