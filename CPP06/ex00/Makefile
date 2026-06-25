# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/06/25 15:07:06 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Converter
CFLAGS = -Wall -Werror -Wextra -g -std=c++98
CC	= c++
SRCS =  ./main.cpp \
		./ScalarConverter.cpp \


all: $(NAME)

$(NAME):
	@$(CC) $(CFLAG) $(SRCS) -o $(NAME)
	
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

	
clean:
#	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean