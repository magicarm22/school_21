# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djast <djast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 17:18:06 by djast             #+#    #+#              #
#    Updated: 2019/03/20 16:57:13 by djast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

NAME_LIBFT = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
 
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
OBJECTS += $(patsubst ./libft/%.c, ./libft/%.o, $(wildcard ./libft/*.c))
LIBS = mlx/libmlx.a
HEADERS = $(wildcard *.h)

all: $(NAME)
	
%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBS) -o $(NAME) -framework OpenGL -framework AppKit

clean:
	@/bin/rm -rf $(OBJECTS)

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(NAME_LIBFT)

re: fclean all
