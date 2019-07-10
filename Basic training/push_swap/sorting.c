/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:36:03 by djast             #+#    #+#             */
/*   Updated: 2019/07/10 12:20:49 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void sort_3_num_ASC(t_stacks *stacks)
{
	unsigned int *seq;

	seq = sequence_1_N(stacks->head_a);
	if (seq[0] == 2 && seq[1] == 1)
		print_and_make_command(stacks, "sa");
	else if (seq[0] == 3 && seq[1] == 2)
	{
		print_and_make_command(stacks, "sa");
		print_and_make_command(stacks, "rra");
	}
	else if (seq[0] == 3 && seq[1] == 1)
		print_and_make_command(stacks, "ra");
	else if (seq[0] == 1 && seq[1] == 3)
	{
		print_and_make_command(stacks, "sa");
		print_and_make_command(stacks, "ra");
	}
	else if (seq[0] == 2 && seq[1] == 3)
		print_and_make_command(stacks, "rra");
}

static void sort_4_to_10_num(t_stacks *stacks, unsigned int list_size)
{
	int size_b;

	if (check_sort(stacks) == SORT_SUCCESS && stacks->head_b == NULL)
		return ;
	while (check_sort(stacks) != SORT_SUCCESS)
	{
		if (stacks->head_a != NULL && stacks->head_a->data == (int)list_size)
			print_and_make_command(stacks, "ra");
		else if (stacks->head_a->data == (int)size_list(stacks->head_b) + 1)
			print_and_make_command(stacks, "pb");
		else if (stacks->head_a->data > stacks->head_a->next->data)
			print_and_make_command(stacks, "sa");
		else
			print_and_make_command(stacks, "ra");
	}
	size_b = size_list(stacks->head_b);
	while (size_b-- != 0)
		print_and_make_command(stacks, "pa");
}

static void put_elem_to_up(t_stacks *stacks, t_sort_info *sort)
{
	if (sort->command == COMMAND_RA)
	{
		if (sort->lower_distance < sort->upper_distance)
			while (sort->lower_distance-- > 0)
				print_and_make_command(stacks, "ra");
		else
			while (sort->upper_distance-- > 0)
				print_and_make_command(stacks, "ra");
	}
	else if (sort->command == COMMAND_RRA)
	{
		if (sort->lower_distance >= sort->upper_distance)
			while (sort->upper_distance-- > 0)
				print_and_make_command(stacks, "rra");
		else
			while (sort->lower_distance-- > 0)
				print_and_make_command(stacks, "rra");
	}
}

static void sort_stack_b_for_chunk_put(t_stacks *stacks, t_sort_info *sort)
{
	int index;

	// printf("%d\n", sort->lower_distance);
	// if (sort->lower_distance == -1)
	// {
	// 	index = find_max(stacks->head_b);
	// 	printf("index: %d\n", index);
	// 	if (index != -1 && index != 0)
	// 	{
	// 		if (index < (int)size_list(stacks->head_b) / 2)
	// 			while (index-- != 0)
	// 				print_and_make_command(stacks, "rb");
	// 		else
	// 			while ((int)size_list(stacks->head_b) - index++ != 0)
	// 				print_and_make_command(stacks, "rrb");
	// 	}
	// }
	// else if (sort->upper_distance == -1)
	// {
	//printf("lower_now: %d upper_now: %d \n", sort->lower_distance, sort->upper_distance);
	if (sort->lower_distance == -1)
	{
		//printf("from_chunk:%d\n", sort->from_chunk - 2);
		index = sort->lower_index == sort->upper_index ? 
							find_elem(stacks->head_b, sort->from_chunk - 1):
							find_elem(stacks->head_b, sort->from_chunk - 2);
		//printf("index_lower: %d\n", index);
		if (index != -1 && index != 0)
		{
			if (index < (int)size_list(stacks->head_b) / 2)
				while (index-- != 0)
					print_and_make_command(stacks, "rb");
			else
				while ((int)size_list(stacks->head_b) - index++ - 1 != 0)
					print_and_make_command(stacks, "rrb");
		}
	}
	else if (sort->upper_distance == -1)
	{
		sort->is_not_start = 1;
		index =	find_elem(stacks->head_b, sort->to_chunk + 2);
		if (index == -1)
		{
			index =	find_elem(stacks->head_b, sort->from_chunk - 1);
			sort->is_not_start = 0;
		}
		else if (index == 0)
			print_and_make_command(stacks, "rb");
		//printf("index_upper: %d\n", index);
		if (index != -1)
		{
			if (index < (int)size_list(stacks->head_b) / 2)
				while (index-- != 0)
					print_and_make_command(stacks, "rb");
			else
				while ((int)size_list(stacks->head_b) - index++ - sort->is_not_start != 0)
					print_and_make_command(stacks, "rrb");
		}
	}
	// }


}

static void sort_many_numbers(t_stacks *stacks, int chunks,
								unsigned int list_size)
{
	t_sort_info *sort;
	int i;
	(void) stacks;
	
	sort = (t_sort_info *)malloc(sizeof(t_sort_info));
	sort->chunks = chunks;
	sort->remainder = list_size % sort->chunks;

	sort->from_chunk_const = 1;
	sort->to_chunk_const = sort->remainder != 0 ? (list_size / sort->chunks) + 1 :
											(list_size / sort->chunks);
	sort->to_chunk_before = sort->to_chunk_const;
	i = 0;
	while (i != sort->chunks)
	{
		sort->from_chunk = sort->from_chunk_const;
		sort->to_chunk = sort->to_chunk_const;

		//printf("FROM: %d TO: %d REM: %d\n", sort->from_chunk, sort->to_chunk, sort->remainder);
		while (sort->to_chunk - sort->from_chunk != -1)
		{
			//print_list("A: ", stacks->head_a);
			get_sort_info(stacks, sort);
			put_elem_to_up(stacks, sort);
			sort_stack_b_for_chunk_put(stacks, sort);
			print_and_make_command(stacks, "pb");
			//print_list("A: ", stacks->head_a);
			//print_list("B: ", stacks->head_b);
		}
		sort->to_chunk_before = sort->to_chunk_const;
		sort->from_chunk_const += sort->remainder > 0 ? (list_size / sort->chunks) + 1:
													(list_size / sort->chunks);
		sort->to_chunk_const += sort->remainder > 1 ? (list_size / sort->chunks) + 1:
											(list_size / sort->chunks);
		sort->remainder--;
		
		chunks = sort->chunks;
		i++;
	}
	while (stacks->head_b != NULL)
	{
		//print_list("A: ", stacks->head_a);
		//print_list("B: ", stacks->head_b);
		i = find_max(stacks->head_b);
		if (i < (int)list_size / 2)
			sort->command = COMMAND_RA;
		else
		{
			i = size_list(stacks->head_b) - i;
			sort->command = COMMAND_RRA;
		}
		while (i-- != 0)
		{
			if (sort->command == COMMAND_RRA)
				print_and_make_command(stacks, "rrb");
			else
				print_and_make_command(stacks, "rb");
		}
		print_and_make_command(stacks, "pa");
	}
	
}

void sorting(t_stacks *stacks)
{
	unsigned int list_size;
	int chunks;

	list_size = size_list(stacks->head_a);
	if (list_size <= 3)
		sort_3_num_ASC(stacks);
	else if (list_size > 3 && list_size <= 10)
		sort_4_to_10_num(stacks, list_size);
	else
	{
		if (list_size > 10 && list_size <= 50)
			chunks = 3;
		if (list_size > 50 && list_size <= 100)
			chunks = 5;
		if (list_size > 100 && list_size <= 200)
			chunks = 7;
		if (list_size > 200 && list_size <= 350)
			chunks = 9;
		if (list_size > 350 && list_size <= 500)
			chunks = 11;
		if (list_size > 500)
			chunks = 15;
		sort_many_numbers(stacks, chunks, list_size);
	}
}
