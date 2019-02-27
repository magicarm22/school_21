# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djast <djast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 12:24:06 by djast             #+#    #+#              #
#    Updated: 2018/11/20 12:24:41 by djast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

clean:
	/bin/rm -rf ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

$(NAME): ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
	ar rc $(NAME) ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
	ranlib $(NAME)

ft_putchar.o:
	gcc -c -Wall -Werror -Wextra ./srcs/ft_putchar.c -I ./includes/

ft_putstr.o:
	gcc -c -Wall -Werror -Wextra ./srcs/ft_putstr.c -I ./includes/

ft_strcmp.o:
	gcc -c -Wall -Werror -Wextra ./srcs/ft_strcmp.c -I ./includes/

ft_strlen.o:
	gcc -c -Wall -Werror -Wextra ./srcs/ft_strlen.c -I ./includes/

ft_swap.o:
	gcc -c -Wall -Werror -Wextra ./srcs/ft_swap.c -I ./includes/