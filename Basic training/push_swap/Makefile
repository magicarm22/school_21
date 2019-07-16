# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djast <djast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 17:18:06 by djast             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2019/07/04 17:09:52 by djast            ###   ########.fr        #
=======
#    Updated: 2019/07/16 14:21:04 by djast            ###   ########.fr        #
>>>>>>> sort_2
#                                                                              #
# **************************************************************************** #

NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker

LIBFT_FOLDER = ./libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

SRC_PUSH_SWAP = push_swap.c stack_swap.c stack_push.c lists.c stack_rotate.c \
<<<<<<< HEAD
		stack_reverse_rotate.c utils.c check_params.c sorting.c \
		translate_list_to_sequence.c printing.c check_sort.c sort_info.c
SRC_CHECKER = checker.c stack_swap.c stack_push.c lists.c stack_rotate.c \
		stack_reverse_rotate.c check_params.c utils.c check_commands.c check_sort.c
=======
		stack_reverse_rotate.c utils.c check_params.c \
		translate_list_to_sequence.c sorting.c check_sort.c printing.c \
		setter_markups.c sorting_by_markups.c sorting_from_b_to_a.c \
		markups_by_index.c commands.c
SRC_CHECKER = checker.c stack_swap.c stack_push.c lists.c stack_rotate.c \
		stack_reverse_rotate.c check_params.c utils.c check_commands.c \
		check_sort.c
>>>>>>> sort_2

OBJ_PUSH_SWAP = $(patsubst %.c, %.o, $(SRC_PUSH_SWAP))
OBJ_CHECKER = $(patsubst %.c, %.o, $(SRC_CHECKER))

LIBS = libft/libft.a
HEADERS = commands.h ./libft/libft.h

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER)
	
%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_PUSH_SWAP): $(OBJ_PUSH_SWAP)
	@$(CC) $(OBJ_PUSH_SWAP) $(LIBS) -o $(NAME_PUSH_SWAP)

$(NAME_CHECKER): $(OBJ_CHECKER)
	@$(CC) $(OBJ_CHECKER) $(LIBS) -o $(NAME_CHECKER)

clean:
	@/bin/rm -rf $(OBJ_PUSH_SWAP)
	@/bin/rm -rf $(OBJ_CHECKER)

fclean: clean
	@/bin/rm -rf $(NAME_PUSH_SWAP)
	@/bin/rm -rf $(NAME_CHECKER)

re: fclean all
