# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 17:18:06 by djast             #+#    #+#              #
#    Updated: 2019/09/26 10:12:59 by eharrag-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_WOLF3D = wolf3d
NAME_EDITOR = editor

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

LIBFT_FOLDER = ./libft
LIBFT = $(LIBFT_FOLDER)/libft.a
LIBFT_HEADER = $(LIBFT_FOLDER)/libft.h

ID_UN := $(shell id -un)

SDL_FOLDER = /Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.10/include/SDL2
SDL_LIB = /Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.10/lib

SDL_TTF_FOLDER = /Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2
SDL_TTF_LIB = /Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/2.0.15/lib

SDL_MIXER_FOLDER = /Users/$(ID_UN)/.brew/Cellar/sdl2_mixer/2.0.4/include/SDL2
SDL_MIXER_LIB = /Users/$(ID_UN)/.brew/Cellar/sdl2_mixer/2.0.4/lib

HEADERS_DIRECTORY = ./includes
HEADERS_WOLF3D = $(HEADERS_DIRECTORY)/wolf3d.h
HEADERS_EDITOR = $(HEADERS_DIRECTORY)/editor.h

LIBS = -lft -L$(LIBFT_FOLDER) -L$(SDL_TTF_LIB) -L$(SDL_MIXER_LIB) -L$(SDL_LIB)  -lSDL2 -lSDL2_ttf -lSDL2_mixer
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_FOLDER) -I$(SDL_TTF_FOLDER) -I$(SDL_MIXER_FOLDER) -I$(SDL_FOLDER)

WOLF3D_FILES =	wolf3d.c \
				maze_generator.c \
				get_info.c \
				utils.c \
				big_loop.c \
				keys.c \
				redraw.c \
				draw_a_weapon.c \
				drawawall.c \
				castaray.c \
				draw_the_sky.c \
				load_bmps.c \
				find_a_wall_hor.c \
				find_a_wall_vert.c \
				happyend.c

EDITOR_FILES =	editor.c \
				draw.c \
				init.c \
				action_mouse.c \
				action_keyboard.c \
				right_panel.c \
				draw_text.c \
				create_sdl_var.c \
				change_map_size.c \
				save_map.c \
				load_map.c \
				utils.c \
				sdl.c \
				free.c

SRC_DIRECTORY = ./sources/
SRC_DIRECTORY_WOLF3D = $(SRC_DIRECTORY)game/
SRC_DIRECTORY_EDITOR = $(SRC_DIRECTORY)editor/

SRC_WOLF3D_FILES = $(addprefix $(SRC_DIRECTORY_WOLF3D), $(WOLF3D_FILES))
SRC_EDITOR_FILES = $(addprefix $(SRC_DIRECTORY_EDITOR), $(EDITOR_FILES))

OBJ_FILES_WOLF3D = $(patsubst %.c, %.o, $(WOLF3D_FILES))
OBJ_FILES_EDITOR = $(patsubst %.c, %.o, $(EDITOR_FILES))

OBJ_DIRECTORY = ./objects/
OBJ_DIRECTORY_WOLF3D = $(OBJ_DIRECTORY)game/
OBJ_DIRECTORY_EDITOR = $(OBJ_DIRECTORY)editor/

OBJ_WOLF3D_FILES = $(addprefix $(OBJ_DIRECTORY_WOLF3D), $(OBJ_FILES_WOLF3D))
OBJ_EDITOR_FILES = $(addprefix $(OBJ_DIRECTORY_EDITOR), $(OBJ_FILES_EDITOR))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME_WOLF3D) $(NAME_EDITOR)

$(NAME_WOLF3D): $(LIBFT) $(OBJ_DIRECTORY) $(OBJ_DIRECTORY_WOLF3D) $(OBJ_WOLF3D_FILES)
	@$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(OBJ_WOLF3D_FILES)  -o $(NAME_WOLF3D)
	@echo "$(RED)$(NAME_WOLF3D) $(GREEN)compiled successfully!$(RESET)"

$(NAME_EDITOR): $(LIBFT) $(OBJ_DIRECTORY) $(OBJ_DIRECTORY_EDITOR) $(OBJ_EDITOR_FILES)
	@$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(OBJ_EDITOR_FILES)  -o $(NAME_EDITOR)
	@echo "$(RED)$(NAME_EDITOR) $(GREEN)compiled successfully!$(RESET)"

$(OBJ_DIRECTORY):
	@mkdir -p $(OBJ_DIRECTORY)

$(OBJ_DIRECTORY_WOLF3D):
	@mkdir -p $(OBJ_DIRECTORY_WOLF3D)

$(OBJ_DIRECTORY_EDITOR):
	@mkdir -p $(OBJ_DIRECTORY_EDITOR)

$(OBJ_DIRECTORY_WOLF3D)%.o : $(SRC_DIRECTORY_WOLF3D)%.c $(HEADERS_WOLF3D) $(HEADERS_EDITOR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJ_DIRECTORY_EDITOR)%.o : $(SRC_DIRECTORY_EDITOR)%.c $(HEADERS_WOLF3D) $(HEADERS_EDITOR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_FOLDER)
	@echo "$(RED)Libft $(GREEN)compiled successfully!$(RESET)"

clean:
	@$(MAKE) -sC $(LIBFT_FOLDER) clean
	@echo "$(RED)Libft $(GREEN)object files were deleted!$(RESET)"
	@/bin/rm -rf $(OBJ_WOLF3D_FILES)
	@/bin/rm -rf $(OBJ_EDITOR_FILES)
	@echo "$(RED)Object $(GREEN)files deleted.$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_FOLDER) fclean
	@echo "$(RED)Libft.a $(GREEN)was deleted.$(RESET)"
	@/bin/rm -rf $(NAME_WOLF3D)
	@echo "$(RED)$(NAME_WOLF3D) $(GREEN)was deleted.$(RESET)"
	@/bin/rm -rf $(NAME_EDITOR)
	@echo "$(RED)$(NAME_EDITOR) $(GREEN)was deleted.$(RESET)"

re: fclean all
