# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/07/11 14:27:56 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = claptrap
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC	= c++
SRCS =  ./ClapTrap.cpp \
		./main.cpp \
		./ScavTrap.cpp \


all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

	
clean:
#	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean