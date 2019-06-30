/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:11:03 by djast             #+#    #+#             */
/*   Updated: 2019/06/24 17:08:03 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void stack_pa(t_stacks *stacks)
{
	t_stack *tmp;

	if (stacks->head_b == NULL)
		return ;
	copy_data_and_add_to_back(stacks->head_a);
	if (stacks->head_a == NULL)
		add_list_to_back(&stacks->head_a, stacks->head_b->data);
	else
		stacks->head_a->data = stacks->head_b->data;

	if (stacks->head_b->next != NULL)
	{
		tmp = stacks->head_b;
		stacks->head_b = stacks->head_b->next;
		free(tmp);
	}
	else
	{
		free(stacks->head_b);
		stacks->head_b = NULL;
	}
}

void stack_pb(t_stacks *stacks)
{
	t_stack *tmp;

	if (stacks->head_a == NULL)
		return ;
	copy_data_and_add_to_back(stacks->head_b);
	if (stacks->head_b == NULL)
		add_list_to_back(&stacks->head_b, stacks->head_a->data);
	else
		stacks->head_b->data = stacks->head_a->data;

	if (stacks->head_a->next != NULL)
	{
		tmp = stacks->head_a;
		stacks->head_a = stacks->head_a->next;
		free(tmp);
	}
	else
	{
		free(stacks->head_a);
		stacks->head_a = NULL;
	}
}
