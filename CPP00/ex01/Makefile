# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/02/03 17:07:53 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = PhoneBook
CFLAGS = -g -Wall -Werror -Wextra -std=c++98 
CC	= c++
SRCS = ./Contact.cpp \
		./PhoneBook.cpp \
		./main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

	
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean