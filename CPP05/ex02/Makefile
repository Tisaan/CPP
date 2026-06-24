# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/06/24 14:52:29 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Form
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC	= c++
SRCS =  ./main.cpp \
		./Bureaucrat.cpp \
		./AForm.cpp \
		./ShrubberyCreationForm.cpp \
		./RobotomyRequestForm.cpp \
		./PresidentialPardonForm.cpp


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