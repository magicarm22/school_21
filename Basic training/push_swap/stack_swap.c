/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:42:26 by djast             #+#    #+#             */
/*   Updated: 2019/07/10 16:21:43 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void stack_sa(t_stacks *stacks)
{
	t_stack	*first_list;
	t_stack	*sec_list;
	t_stack *third_list;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL)
		return ;
	first_list = stacks->head_a;
	sec_list = first_list->next;
	third_list = sec_list->next;
	stacks->head_a = sec_list;
	sec_list->next = first_list;
	first_list->next = third_list;
}

void stack_sb(t_stacks *stacks)
{
	t_stack	*first_list;
	t_stack	*sec_list;
	t_stack *third_list;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
	first_list = stacks->head_b;
	sec_list = first_list->next;
	third_list = sec_list->next;
	stacks->head_b = sec_list;
	sec_list->next = first_list;
	first_list->next = third_list;
}

void stack_ss(t_stacks *stacks)
{
	stack_sa(stacks);
	stack_sb(stacks);
}