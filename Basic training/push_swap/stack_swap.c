/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:42:26 by djast             #+#    #+#             */
/*   Updated: 2019/06/19 20:29:46 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void stack_sa(t_stacks *stacks)
{
	int		tmp;
	t_stack	*sec_list;

	if (stacks->head_a == NULL || stacks->head_a->next == NULL)
		return ;
	sec_list = stacks->head_a->next;
	tmp = sec_list->data;
	sec_list->data = stacks->head_a->data;
	stacks->head_a->data = tmp;
}

void stack_sb(t_stacks *stacks)
{
	int		tmp;
	t_stack	*sec_list;

	if (stacks->head_b == NULL || stacks->head_b->next == NULL)
		return ;
	sec_list = stacks->head_b->next;
	tmp = sec_list->data;
	sec_list->data = stacks->head_b->data;
	stacks->head_b->data = tmp;
}

void stack_ss(t_stacks *stacks)
{
	stack_sa(stacks);
	stack_sb(stacks);
}