/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:11:03 by djast             #+#    #+#             */
/*   Updated: 2019/08/25 12:56:08 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	stack_pa(t_stacks *stacks)
{
	t_stack *first_in_a;
	t_stack *first_in_b;
	t_stack *second_in_b;

	if (stacks->head_b == NULL)
		return ;
	first_in_a = stacks->head_a;
	first_in_b = stacks->head_b;
	second_in_b = first_in_b->next;
	stacks->head_a = first_in_b;
	stacks->head_a->next = first_in_a;
	stacks->head_b = second_in_b;
}

void	stack_pb(t_stacks *stacks)
{
	t_stack *first_in_b;
	t_stack *first_in_a;
	t_stack *second_in_a;

	if (stacks->head_a == NULL)
		return ;
	first_in_a = stacks->head_a;
	second_in_a = first_in_a->next;
	first_in_b = stacks->head_b;
	stacks->head_b = first_in_a;
	stacks->head_b->next = first_in_b;
	stacks->head_a = second_in_a;
}
