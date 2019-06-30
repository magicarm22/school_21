/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:12:35 by djast             #+#    #+#             */
/*   Updated: 2019/06/24 16:56:36 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void stack_rb(t_stacks *stacks)
{
	t_stack *cur_list;
	t_stack *prev_list;
	int		tmp_data;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
	prev_list = stacks->head_b;
	cur_list = stacks->head_b->next;
	tmp_data = prev_list->data;
	while (cur_list != NULL)
	{
		prev_list->data = cur_list->data;
		prev_list = cur_list;
		cur_list = cur_list->next;
	}
	prev_list->data = tmp_data;
}

void stack_ra(t_stacks *stacks)
{
	t_stack *cur_list;
	t_stack *prev_list;
	int		tmp_data;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL)
		return ;
	prev_list = stacks->head_a;
	cur_list = stacks->head_a->next;
	tmp_data = prev_list->data;
	while (cur_list != NULL)
	{
		prev_list->data = cur_list->data;
		prev_list = cur_list;
		cur_list = cur_list->next;
	}
	prev_list->data = tmp_data;
}

void stack_rr(t_stacks *stacks)
{
	stack_ra(stacks);
	stack_rb(stacks);
}