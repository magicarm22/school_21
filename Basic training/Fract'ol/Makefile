# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djast <djast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 17:18:06 by djast             #+#    #+#              #
#    Updated: 2019/06/08 15:27:54 by djast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT_FOLDER = ./libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
SRC = calculate.c mandatory_fractols.c bonus_fractols.c fractol.c key.c mlx.c threads.c utils.c
OBJ = $(patsubst %.c, %.o, $(SRC))

LIBS = mlx/libmlx.a libft/libft.a
HEADERS = fractol.h ./libft/libft.h

all: $(NAME)
	
%.o: %.c $(HEADERS)
	
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME) -framework OpenGL -framework AppKit

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
