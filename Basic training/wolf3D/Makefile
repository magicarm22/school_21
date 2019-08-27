# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djast <djast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 17:18:06 by djast             #+#    #+#              #
#    Updated: 2019/08/27 18:55:49 by djast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_WOLF3D = wold3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

LIBFT_FOLDER = ./libft
LIBFT = $(LIBFT_FOLDER)/libft.a
LIBFT_HEADER = $(LIBFT_FOLDER)/libft.h

ID_UN := $(shell id -un)

SDL_FOLDER = /Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.9_1/include/SDL2
SDL_LIB = /Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.9_1/lib

HEADERS_DIRECTORY = ./includes
HEADERS = $(HEADERS_DIRECTORY)/wolf3d.h

LIBS = -lft -L$(LIBFT_FOLDER) -L$(SDL_LIB) -lSDL2
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_FOLDER) -I$(SDL_FOLDER)

COMMON_FILES =	main.c \
				maze_generator.c \
				utils.c

SRC_DIRECTORY = ./sources/
SRC_COMMON_FILES = $(addprefix $(SRC_DIRECTORY), $(COMMON_FILES))

OBJ_FILES_COMMON = $(patsubst %.c, %.o, $(COMMON_FILES))

OBJ_DIRECTORY = ./objects/
OBJ_COMMON_FILES = $(addprefix $(OBJ_DIRECTORY), $(OBJ_FILES_COMMON))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME_WOLF3D)

$(NAME_WOLF3D): $(LIBFT) $(OBJ_DIRECTORY) $(OBJ_COMMON_FILES)
	@$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(OBJ_COMMON_FILES)  -o $(NAME_WOLF3D)
	@echo "$(RED)$(NAME_WOLF3D) $(GREEN)compiled successfully!$(RESET)"

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
	@echo "$(RED)Object $(GREEN)files deleted.$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_FOLDER) fclean
	@echo "$(RED)Libft.a $(GREEN)was deleted.$(RESET)"
	@/bin/rm -rf $(NAME_WOLF3D)
	@echo "$(RED)$(NAME_WOLF3D) $(GREEN)was deleted.$(RESET)"

re: fclean all
