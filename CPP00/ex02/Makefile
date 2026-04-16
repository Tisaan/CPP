# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/04/01 18:48:11 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#pour diff les deux output
#./noNameSpecified > out
#[rm les 18 premiers character e.g les timestamps]
# cut -c 18- out > out.txt
# cut -c 18- 19920104_091532.log > log.txt
# diff out.txt log.txt

NAME = noNameSpecified
CFLAGS = -g -Wall -Werror -Wextra -std=c++98 
CC	= c++
SRCS =  Account.cpp \
		tests.cpp \

OBJS= $(SRCS:.cpp=.o)

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