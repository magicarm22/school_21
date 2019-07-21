/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:59:37 by djast             #+#    #+#             */
/*   Updated: 2019/07/16 15:54:44 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void stack_rra(t_stacks *stacks)
{
	t_stack	*first_list;
	t_stack	*prev_last_list;
	t_stack *last_list;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL)
		return ;
	first_list = stacks->head_a;
	prev_last_list = first_list;
	while (prev_last_list->next->next != NULL)
		prev_last_list = prev_last_list->next;
	last_list = prev_last_list->next;
	stacks->head_a = last_list;
	last_list->next = first_list;
	prev_last_list->next = NULL;
}

void stack_rrb(t_stacks *stacks)
{
	t_stack	*first_list;
	t_stack	*prev_last_list;
	t_stack *last_list;
	int i;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
	first_list = stacks->head_b;
	prev_last_list = first_list;
	i = 0;
	while (prev_last_list->next->next != NULL)
		prev_last_list = prev_last_list->next;
	last_list = prev_last_list->next;
	stacks->head_b = last_list;
	last_list->next = first_list;
	prev_last_list->next = NULL;
}

void stack_rrr(t_stacks *stacks)
{
	stack_rra(stacks);
	stack_rrb(stacks);
}
