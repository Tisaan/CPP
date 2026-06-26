# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/06/26 15:50:20 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Converter
CXXFLAGS = -Wall -Werror -Wextra -g -O0 -std=c++98 -fno-omit-frame-pointer
CXX	= clang++
SRCS =  ./main.cpp \
		./ScalarConverter.cpp \


all: $(NAME)

$(NAME):
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	
%.o : %.c
	@$(CXX) $(CXXFLAGS) -c $< -o $@

	
clean:
#	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean