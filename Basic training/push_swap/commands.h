/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:43:08 by djast             #+#    #+#             */
/*   Updated: 2019/06/30 16:12:26 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNANDS_H
# define CONNANDS_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

# define CHECK_ERROR -1
# define CHECK_SUCCESS 1
# define COMMAND_SUCCESS 1
# define COMMAND_ERROR -1
# define COMMAND_SIZE 4
# define SORT_ERROR -1
# define SORT_SUCCESS 1

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacks
{
	t_stack *head_a;
	t_stack *head_b;
}				t_stacks;

void stack_sa(t_stacks *stacks);
void stack_sb(t_stacks *stacks);
void stack_ss(t_stacks *stacks);

void stack_pa(t_stacks *stacks);
void stack_pb(t_stacks *stacks);

void stack_ra(t_stacks *stacks);
void stack_rb(t_stacks *stacks);
void stack_rr(t_stacks *stacks);

void stack_rra(t_stacks *stacks);
void stack_rrb(t_stacks *stacks);
void stack_rrr(t_stacks *stacks);






void add_list_to_back(t_stack **stack, int data);
void print_list(char *label, t_stack *stack);
int copy_data_to_next_list(t_stack *stack);
void copy_data_and_add_to_back(t_stack *stack);
int check_params(int argc, char const *argv[], t_stacks *stacks);
unsigned int		ft_num_size_with_sign(intmax_t n);
t_stacks *init_lists();
int check_commands(t_stacks *stacks, char command[3]);
unsigned int		size_list(t_stack *stack);
void				translate_to_1_N(t_stack *head_a);
void				sorting(t_stacks *stacks);

#endif