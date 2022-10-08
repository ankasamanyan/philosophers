# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 08:40:39 by ankasamanya       #+#    #+#              #
#    Updated: 2022/10/08 18:58:42 by akasaman         ###   ########.fr        #
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
	@echo "\033[0;35m✨Philosophers successfully compiled!✨"
	@echo "								"
	@echo "         ,..........   .........., "
	@echo "     ,..,'          '.'          ',.., "
	@echo "    ,' ,'            :            ', ', "
	@echo "   ,' ,'             :             ', ', "
	@echo "  ,' ,'              :              ', ', "
	@echo " ,' ,'............., : ,.............', ', "
	@echo ",'  '............   '.'   ............'  ', "
	@echo " '''''''''''''''''';''';'''''''''''''''''' "
	@echo "                    ''' \033[0m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;34m✨Philosophers successfully cleaned!✨\033[0m"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean art re