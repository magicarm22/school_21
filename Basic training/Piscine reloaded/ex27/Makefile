# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djast <djast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:06:45 by djast             #+#    #+#              #
#    Updated: 2018/11/20 13:11:56 by djast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

all: $(NAME)

clean:
	@/bin/rm -rf ft_display_file.o

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

$(NAME): ft_display_file.o
	@gcc ft_display_file.o -o $(NAME)

ft_display_file.o: 
	@gcc -c -Wall -Werror -Wextra ./ft_display_file.c