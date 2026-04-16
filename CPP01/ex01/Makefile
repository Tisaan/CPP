# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/04/16 16:12:24 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = horde
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC	= c++
SRCS = 	./Zombie.cpp \
		./zombieHorde.cpp \
		./main.cpp


all: $(NAME)

$(NAME):
	@$(CC) $(SRCS) -o $(NAME)
	
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

	
clean:
#	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean