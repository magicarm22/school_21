/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_by_markups.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:57:10 by djast             #+#    #+#             */
/*   Updated: 2019/07/11 13:31:52 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int find_false_markup(t_stack *head)
{
	unsigned int cur_index;
	t_stack *cur_list;

	cur_index = 0;
	cur_list = head;
	while (cur_list != NULL)
	{
		if (cur_list->markup == 0)
			return (cur_index);
		cur_list = cur_list->next;
		cur_index++;
	}
	return (-1);
}

static int count_of_markups(t_stack *head)
{
	t_stack *cur_list;
	int count_of_markups;

	cur_list = head;
	count_of_markups = 0;
	while (cur_list != NULL)
	{
		if (cur_list->markup == 1)
			count_of_markups++;
		cur_list = cur_list->next;
	}
	return (count_of_markups);
}

static int *get_markups_copy(t_stack *head)
{
	t_stack *cur_list;
	int *copy_markups;
	unsigned int i;

	i = 0;
	cur_list = head;
	copy_markups = (int *)malloc(sizeof(int) * size_list(head));
	while (i != size_list(head))
	{
		copy_markups[i] = cur_list->markup;
		cur_list = cur_list->next;
		i++;
	}
	return copy_markups;
}

static void set_markups_copy(t_stack *head, int *copy_markups)
{
	t_stack *cur_list;
	unsigned int i;

	i = 0;
	cur_list = head;
	while (i != size_list(head))
	{
		cur_list->markup = copy_markups[i];
		cur_list = cur_list->next;
		i++;
	}
	free(copy_markups);
}

int swap_is_needed(t_stacks *stacks)
{
	int before_swap;
	int after_swap;
	int *copy_markups;
	
	copy_markups = get_markups_copy(stacks->head_a);
	before_swap = count_of_markups(stacks->head_a);
	clear_markup(stacks->head_a);
	stack_sa(stacks);
	after_swap = set_markups(stacks->head_a);
	clear_markup(stacks->head_a);
	stack_sa(stacks);
	set_markups_copy(stacks->head_a, copy_markups);
	if (before_swap < after_swap)
		return (1);
	return (0);
}