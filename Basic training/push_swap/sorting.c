/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:36:03 by djast             #+#    #+#             */
/*   Updated: 2019/07/16 18:17:53 by djast            ###   ########.fr       */
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

static void sort_many_numbers(t_stacks *stacks, unsigned int list_size,
														t_commands **commands)
{
	int index_with_max_markups;
	int min_index;
	int elem;
	

	//print_list("a: ", stacks->head_a);
	//print_markups(stacks->head_a);
	//print_list("b: ", stacks->head_b);
	index_with_max_markups = find_index_with_max_markups(stacks, list_size);
	//printf("%d %d\n", index_with_max_markups, get_elem_by_index(stacks->head_a, index_with_max_markups));
	set_selected_markups(stacks->head_a, index_with_max_markups);

	elem = get_elem_by_index(stacks->head_a, index_with_max_markups);
//	printf("STEP 1\n");
//	printf("%d\n", get_elem_by_index(stacks->head_a, find_true_markup(stacks->head_a)));
	while (find_false_markup(stacks->head_a) != -1)
	{

		// print_list("a: ", stacks->head_a);
		// print_markups(stacks->head_a);
		// print_list("b: ", stacks->head_b);
		// getchar();
		if ((index_with_max_markups = swap_is_needed(stacks)) != 0)
		{
			//print_list("a: ", stacks->head_a);
			//print_markups(stacks->head_a);
			//print_list("b: ", stacks->head_b);
			//getchar();
			//printf("sa\n");
			make_and_add_command(stacks, commands, "sa");
			clear_markup(stacks->head_a);
			set_selected_markups(stacks->head_a, index_with_max_markups);
		}
		else if (stacks->head_a->markup == 0)
		{
			//printf("pb\n");
			make_and_add_command(stacks, commands, "pb");
		}
		else
		{
			//printf("ra\n");
			make_and_add_command(stacks, commands, "ra");
		}
		//printf("AAAA\n");
		
	}
	// 	print_list("a: ", stacks->head_a);
	// 	print_markups(stacks->head_a);
	// 	print_list("b: ", stacks->head_b);
	// getchar();
	
	//print_list("a: ", stacks->head_a);
	//print_list("b: ", stacks->head_b);
	//printf("STEP 2\n");

	while (stacks->head_b != NULL)
	{
		// getchar();
	 	min_index = choose_element(stacks);
	 	put_index_to_b_up(stacks, commands, min_index);
	 // 	print_list("a: ", stacks->head_a);
		// print_list("b: ", stacks->head_b);
	 // 	getchar();
	 	create_place_in_a(stacks, commands);
	 // 	print_list("a: ", stacks->head_a);
		// print_list("b: ", stacks->head_b);
	 // 	getchar();
	 	make_and_add_command(stacks, commands, "pa");
	 	// print_list("a: ", stacks->head_a);
		// print_list("b: ", stacks->head_b);
	}
	//exit(0);
	//getchar();
	//printf("STEP 3\n");
	align_a(stacks, commands);
	//print_list("a: ", stacks->head_a);
	//printf("Status: %d", check_sort(stacks));
}

void sorting(t_stacks *stacks, t_commands **commands)
{
	unsigned int list_size;

	list_size = size_list(stacks->head_a);
	if (list_size <= 3)
		sort_3_num_ASC(stacks);
	else if (list_size > 3 && list_size <= 10)
		sort_4_to_10_num(stacks, list_size);
	else
		sort_many_numbers(stacks, list_size, commands);
}
