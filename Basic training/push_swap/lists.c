/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:39:05 by djast             #+#    #+#             */
/*   Updated: 2019/06/30 15:24:51 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_stacks *init_lists()
{
	t_stacks *stacks;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	stacks->head_a = NULL;
	stacks->head_b = NULL;
	return (stacks);
}

void print_list(char *label, t_stack *stack)
{
	t_stack *cur_list;

	cur_list = stack;
	ft_putstr(label);
	if (cur_list == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	while (cur_list->next != NULL) 
	{
		ft_putnbr(cur_list->data);
		write(1, " --> ", 5);
		cur_list = cur_list->next;
	}
	ft_putnbr(cur_list->data);
	write(1, "\n", 1);
}

void add_list_to_back(t_stack **stack, int data)
{
	t_stack *cur_list;
	
	if (*stack == NULL)
	{
		*stack = (t_stack *) malloc(sizeof(t_stack));
		(*stack)->data = data;
		(*stack)->next = NULL;
		return ;
	}
	cur_list = *stack;

	while (cur_list->next != NULL)
		cur_list = cur_list->next;

	cur_list->next = (t_stack *) malloc(sizeof(t_stack));
	cur_list->next->data = data;
	cur_list->next->next = NULL;
}

int copy_data_to_next_list(t_stack *stack)
{
	t_stack *cur_list;
	int		tmp_cur_data;
	int		tmp_prev_data;

	cur_list = stack;
	tmp_prev_data = 0;
	tmp_cur_data = 0;
	while (cur_list != NULL)
	{
		tmp_cur_data = cur_list->data;
		cur_list->data = tmp_prev_data;
		tmp_prev_data = tmp_cur_data;
		cur_list = cur_list->next;
	}
	return tmp_prev_data;
}

void copy_data_and_add_to_back(t_stack *stack)
{	
	int tmp_data;

	tmp_data = copy_data_to_next_list(stack);
	add_list_to_back(&stack, tmp_data);
}