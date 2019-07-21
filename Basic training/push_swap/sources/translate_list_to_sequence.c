/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_list_to_sequence.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:33:53 by djast             #+#    #+#             */
/*   Updated: 2019/07/18 19:28:20 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static unsigned int		check_if_index_in_array(unsigned int *array,
												unsigned int cur_index,
												unsigned int already_added)
{
	unsigned int i;

	i = 0;
	while (i < already_added)
	{
		if (array[i] == cur_index)
		{
			return 1;
		}
		i++;
	}
	return 0;
}

static unsigned int		find_max_index(unsigned int *array, t_stack *head_a,
										int already_added)
{
	t_stack *cur_list;
	int min;
	unsigned int min_index;
	unsigned int cur_index;

	cur_list = head_a;
	min = INT_MAX;
	cur_index = 0;
	min_index = 0;
	while (cur_list != NULL)
	{
		cur_index++;
		if (cur_list->data < min)
		{
			if (check_if_index_in_array(array, cur_index, already_added) == 0)
			{
				min = cur_list->data;
				min_index = cur_index;
			}
		}
		cur_list = cur_list->next;
	}
	return (min_index);
}

unsigned int *sequence_1_N(t_stack *head_a)
{
	unsigned int *array;
	int min_index;
	int i;
	int list_size;

	list_size = size_list(head_a);

	array = (unsigned int *)malloc(sizeof(unsigned int) * list_size);
	i = 0;
	while (i < list_size)
	{
		min_index = find_max_index(array, head_a, i);
		array[i] = min_index;
		i++;
	}
	return (array);
}

void translate_to_1_N(t_stack *head_a)
{
	unsigned int *sequence;
	t_stack *cur_list;
	unsigned int i;
	unsigned int j;

	sequence = sequence_1_N(head_a);
	i = 1;
	cur_list = head_a;
	while (i <= size_list(head_a))
	{
		j = 0;
		while (j < size_list(head_a))
		{
			if (i == sequence[j])
			{
				cur_list->data = j + 1;
				break;
			}
			j++;
		}
		cur_list = cur_list->next;
		i++;
	} 
}
