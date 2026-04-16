# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/02/03 13:24:26 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC	= c++
SRCS = ./megaphone.cpp


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