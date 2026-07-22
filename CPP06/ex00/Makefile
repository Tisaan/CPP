# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/07/15 15:58:52 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Converter
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98
CXX	= c++
SRCS =  ./main.cpp \
        ./ScalarConverter.cpp \


OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	
%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

	
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean