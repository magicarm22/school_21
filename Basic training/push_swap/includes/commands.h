/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:43:08 by djast             #+#    #+#             */
/*   Updated: 2019/07/21 20:05:11 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNANDS_H
# define CONNANDS_H
# include "libft.h"
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <SDL.h>
# include "get_next_line.h"

# define SIZE_WINDOW_X 2550
# define SIZE_WINDOW_Y 1440

# define SIZE_STACKS_X 2000

# define CHECK_ERROR -1
# define CHECK_SUCCESS 1
# define COMMAND_SUCCESS 1
# define COMMAND_ERROR -1
# define COMMAND_SIZE 4
# define SORT_ERROR -1
# define SORT_SUCCESS 1

typedef struct		s_stack
{
	int				data;
	int				markup : 2;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack *head_a;
	t_stack *head_b;
}					t_stacks;

typedef struct			s_commands
{
	char				*data;
	struct s_commands	*next;
}						t_commands;

typedef struct			s_SDL
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	t_stacks *stacks;
	int stack_size;
	int speed;
}						t_SDL;


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



void				add_list_to_back(t_stack **stack, int data);
void				print_list(char *label, t_stack *stack);
int					check_params(int argc, char const *argv[],
												t_stacks *stacks);
unsigned int		ft_num_size_with_sign(intmax_t n);
t_stacks			*init_lists();
int					check_commands(t_stacks *stacks, char command[3]);
unsigned int		size_list(t_stack *stack);
void				translate_to_1_N(t_stack *head_a);
void				sorting(t_stacks *stacks, t_commands **commands);
void				print_and_make_command(t_stacks *stacks, char *command);
int					check_sort(t_stacks *stacks);
unsigned int		*sequence_1_N(t_stack *head_a);
int					find_index_with_max_markups(t_stacks *stacks,
										unsigned int list_size);
int					set_selected_markups(t_stack *head,
									int index_with_max_markups);
int					find_false_markup(t_stack *head);
int swap_is_needed(t_stacks *stacks);
int set_markups(t_stack *start, t_stack *markup_list);
void print_markups(t_stack *stack);
void clear_markup(t_stack *head);
unsigned int choose_element(t_stacks *stacks);
int get_elem_by_index(t_stack *head, int index);
int find_min(t_stack *stack);
void put_index_to_b_up(t_stacks *stacks, t_commands **commands, unsigned int index);
void create_place_in_a(t_stacks *stacks, t_commands **commands);
void align_a(t_stacks *stacks, t_commands **commands);
int get_last_elem(t_stack *head);
int find_true_markup(t_stack *head);
int find_index_with_max_markups_by_index(t_stacks *stacks,
												unsigned int list_size);
int set_markups_by_index(t_stack *head, unsigned int cur_index);
int get_index_by_elem(t_stack *head, int elem);
void add_command(t_commands **commands, char *data);
void print_commands(t_commands **commands);
void make_and_add_command(t_stacks *stacks, t_commands **commands, char *data);
void optimizate_commands(t_commands **commands, char *command1, char *command2,
								char *command_result);
#endif