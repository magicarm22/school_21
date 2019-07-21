/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:39:05 by djast             #+#    #+#             */
/*   Updated: 2019/07/16 15:46:44 by djast            ###   ########.fr       */
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

void print_markups(t_stack *stack)
{
	t_stack *cur_list;

	cur_list = stack;
	if (cur_list == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	write(1, "    ", 4);
	while (cur_list->next != NULL) 
	{
		ft_putnbr(cur_list->markup);
		write(1, " --> ", 5);
		cur_list = cur_list->next;
	}
	ft_putnbr(cur_list->markup);
	write(1, "\n", 1);
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
		(*stack)->markup = 0;
		(*stack)->next = NULL;
		return ;
	}
	cur_list = *stack;

	while (cur_list->next != NULL)
		cur_list = cur_list->next;

	cur_list->next = (t_stack *) malloc(sizeof(t_stack));
	cur_list->next->data = data;
	cur_list->next->markup = 0;
	cur_list->next->next = NULL;
}
