# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djast <djast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 17:18:06 by djast             #+#    #+#              #
#    Updated: 2019/07/21 20:27:53 by djast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker
NAME_VISUAL = visualize

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

LIBFT_FOLDER = ./libft
LIBFT = $(LIBFT_FOLDER)/libft.a
LIBFT_HEADER = $(LIBFT_FOLDER)/libft.h

ID_UN := $(shell id -un)

SDL_FOLDER = /Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.9_1/include/SDL2
SDL_LIB = /Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.9_1/lib

HEADERS_DIRECTORY = ./includes
HEADERS = $(HEADERS_DIRECTORY)/commands.h

LIBS = -lft -L$(LIBFT_FOLDER) -L$(SDL_LIB) -lSDL2
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_FOLDER) -I$(SDL_FOLDER)

COMMON_FILES =	stack_swap.c \
				stack_push.c \
				lists.c \
				stack_rotate.c \
				stack_reverse_rotate.c \
				utils.c \
				check_sort.c \
				check_params.c \
				check_commands.c \
				translate_list_to_sequence.c \
				sorting.c \
				printing.c \
				setter_markups.c \
				sorting_by_markups.c \
				sorting_from_b_to_a.c \
				markups_by_index.c \
				commands.c

PUSH_SWAP_FILES = push_swap.c
CHECKER_FILES = checker.c
VISUAL_FILES = visualize.c


SRC_DIRECTORY = ./sources/
SRC_COMMON_FILES = $(addprefix $(SRC_DIRECTORY), $(COMMON_FILES))
SRC_PUSH_SWAP = $(addprefix $(SRC_DIRECTORY), $(PUSH_SWAP_FILES))
SRC_CHECKER = $(addprefix $(SRC_DIRECTORY), $(CHECKER_FILES))
SRC_VISUAL = $(addprefix $(SRC_DIRECTORY), $(VISUAL_FILES))

OBJ_FILES_COMMON = $(patsubst %.c, %.o, $(COMMON_FILES))
OBJ_FILES_PUSH_SWAP = $(patsubst %.c, %.o, $(PUSH_SWAP_FILES))
OBJ_FILES_CHECKER = $(patsubst %.c, %.o, $(CHECKER_FILES))
OBJ_FILES_VISUAL = $(patsubst %.c, %.o, $(VISUAL_FILES))

OBJ_DIRECTORY = ./objects/
OBJ_COMMON_FILES = $(addprefix $(OBJ_DIRECTORY), $(OBJ_FILES_COMMON))
OBJ_PUSH_SWAP = $(addprefix $(OBJ_DIRECTORY), $(OBJ_FILES_PUSH_SWAP))
OBJ_CHECKER = $(addprefix $(OBJ_DIRECTORY), $(OBJ_FILES_CHECKER))
OBJ_VISUAL = $(addprefix $(OBJ_DIRECTORY), $(OBJ_FILES_VISUAL))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER) $(NAME_VISUAL)

$(NAME_PUSH_SWAP): $(LIBFT) $(OBJ_DIRECTORY) $(OBJ_COMMON_FILES) $(OBJ_PUSH_SWAP)
	@$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(OBJ_COMMON_FILES) $(OBJ_PUSH_SWAP)  -o $(NAME_PUSH_SWAP)
	@echo "$(RED)$(NAME_PUSH_SWAP) $(GREEN)compiled successfully!$(RESET)"

$(NAME_CHECKER): $(LIBFT) $(OBJ_DIRECTORY) $(OBJ_COMMON_FILES) $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) $(OBJ_CHECKER) $(OBJ_COMMON_FILES) $(LIBS) -o $(NAME_CHECKER)
	@echo "$(RED)$(NAME_CHECKER) $(GREEN)compiled successfully!$(RESET)"

$(NAME_VISUAL): $(LIBFT) $(OBJ_DIRECTORY) $(OBJ_COMMON_FILES) $(OBJ_VISUAL)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_COMMON_FILES) $(OBJ_VISUAL) $(LIBS) -o $(NAME_VISUAL)
	@echo "$(RED)$(NAME_VISUAL) $(GREEN)compiled successfully!$(RESET)"

$(OBJ_DIRECTORY):
	@mkdir -p $(OBJ_DIRECTORY)

$(OBJ_DIRECTORY)%.o : $(SRC_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_FOLDER)
	@echo "$(RED)Libft $(GREEN)compiled successfully!$(RESET)"

clean:
	@$(MAKE) -sC $(LIBFT_FOLDER) clean
	@echo "$(RED)Libft $(GREEN)object files were deleted!$(RESET)"
	@/bin/rm -rf $(OBJ_COMMON_FILES)
	@/bin/rm -rf $(OBJ_CHECKER)
	@/bin/rm -rf $(OBJ_VISUAL)
	@/bin/rm -rf $(OBJ_PUSH_SWAP)
	@echo "$(RED)Object $(GREEN)files deleted.$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_FOLDER) fclean
	@echo "$(RED)Libft.a $(GREEN)was deleted.$(RESET)"
	@/bin/rm -rf $(NAME_PUSH_SWAP)
	@echo "$(RED)$(NAME_PUSH_SWAP) $(GREEN)was deleted.$(RESET)"
	@/bin/rm -rf $(NAME_CHECKER)
	@echo "$(RED)$(NAME_CHECKER) $(GREEN)was deleted.$(RESET)"
	@/bin/rm -rf $(NAME_VISUAL)
	@echo "$(RED)$(NAME_VISUAL) $(GREEN)was deleted.$(RESET)"

re: fclean all
