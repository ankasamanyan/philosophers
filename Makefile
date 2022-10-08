# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 08:40:39 by ankasamanya       #+#    #+#              #
#    Updated: 2022/10/08 09:31:56 by ankasamanya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[0;35m•\033[0m\c"

$(NAME): $(OBJ) $(SRC)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\033[0;35mPhilosophers successfully compiled!✨\033[0m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;34mPhilosophers successfully cleaned!✨\033[0m"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re