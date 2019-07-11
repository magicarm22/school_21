/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:42:47 by djast             #+#    #+#             */
/*   Updated: 2019/07/11 12:53:46 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

unsigned int		ft_num_size_with_sign(intmax_t n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
		count++;
	while ((n = n / 10) != 0)
		count++;
	return (count + 1);
}

unsigned int		size_list(t_stack *stack)
{
	unsigned int size;
	t_stack *cur_list;

	cur_list = stack;
	size = 0;
	while (cur_list != NULL)
	{
		size++;
		cur_list = cur_list->next;
	}
	return (size);
}

int get_elem_by_index(t_stack *head, int index)
{
	t_stack *cur_list;

	cur_list = head;
	while (index-- != 0)
		cur_list = cur_list->next;
	return (cur_list->data);
}

int find_min(t_stack *stack)
{
	t_stack *cur_list;
	int min;
	int cur_index;
	int min_index;

	cur_list = stack;
	if (cur_list == NULL)
		return (-1);
	min = cur_list->data;
	cur_list = cur_list->next;
	cur_index = 1;
	min_index = 0;
	while (cur_list != NULL)
	{
		if (cur_list->data < min)
		{
			min = cur_list->data;
			min_index = cur_index;
		}
		cur_list = cur_list->next;
		cur_index++;
	}
	return (min_index);
}