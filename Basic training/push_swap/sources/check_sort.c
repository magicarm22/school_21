/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:19:35 by djast             #+#    #+#             */
/*   Updated: 2019/07/18 19:15:31 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int check_sort(t_stacks *stacks)
{
	int success;
	t_stack *cur_list;
	t_stack *prev_list;

	success = 1;
	if (stacks->head_a == NULL)
		return (SORT_ERROR);
	prev_list = stacks->head_a;
	cur_list = prev_list->next;
	while (cur_list != NULL)
	{
		if (prev_list->data > cur_list->data)
		{
			success = 0;
			break;
		}
		prev_list = cur_list;
		cur_list = cur_list->next;
	}
	if (success == 1)
		return (SORT_SUCCESS);
	else
		return (SORT_ERROR);
}