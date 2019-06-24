/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:59:37 by djast             #+#    #+#             */
/*   Updated: 2019/06/24 17:17:08 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void stack_rra(t_stacks *stacks)
{
	int		tmp_data;

	if (stacks->head_a != NULL)
	{
		tmp_data = copy_data_to_next_list(stacks->head_a);
		stacks->head_a->data = tmp_data;
	}
}

void stack_rrb(t_stacks *stacks)
{
	int		tmp_data;

	if (stacks->head_b != NULL)
	{
		tmp_data = copy_data_to_next_list(stacks->head_b);
		stacks->head_b->data = tmp_data;
	}
}

void stack_rrr(t_stacks *stacks)
{
	stack_rra(stacks);
	stack_rrb(stacks);
}
