/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:12:35 by djast             #+#    #+#             */
/*   Updated: 2019/07/10 16:51:53 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void stack_ra(t_stacks *stacks)
{
	t_stack	*first_list;
	t_stack	*sec_list;
	t_stack *last_list;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL)
		return ;
	first_list = stacks->head_a;
	sec_list = first_list->next;
	last_list = sec_list;
	while (last_list->next != NULL)
		last_list = last_list->next;

	stacks->head_a = sec_list;
	first_list->next = NULL;
	last_list->next = first_list;
}

void stack_rb(t_stacks *stacks)
{
	t_stack	*first_list;
	t_stack	*sec_list;
	t_stack *last_list;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
	first_list = stacks->head_b;
	sec_list = first_list->next;
	last_list = sec_list;
	while (last_list->next != NULL)
		last_list = last_list->next;
	
	stacks->head_b = sec_list;
	first_list->next = NULL;
	last_list->next = first_list;
}

void stack_rr(t_stacks *stacks)
{
	stack_ra(stacks);
	stack_rb(stacks);
}