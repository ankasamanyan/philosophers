# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 08:40:39 by ankasamanya       #+#    #+#              #
#    Updated: 2022/10/15 14:20:03 by ankasamanya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf

PINK	:= \033[0;35m
PURPLE	:= \033[0;34m
RESET	:= \033[0m

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[0;35m•\033[0m\c"

$(NAME): $(OBJ) $(SRC)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\033[0;35m✨Philosophers successfully compiled!✨"
	@echo "	"
	@echo "      	           ${RESET},..........   ..........,${PURPLE} "
	@echo "${RESET} (\ ${PURPLE}           ,..${RESET},' ✨✨✨✨ '.'  ✨✨✨  ',${PURPLE}.., "
	@echo "${RESET} \ \ ${PURPLE}         ,' ${RESET},'  ✨eat ✨  :   ✨die✨  ',${PURPLE} ', "
	@echo "${RESET}  \ \ ${PURPLE} 	     ,' ${RESET},'  ✨sleep✨  :    ✨die✨  ',${PURPLE} ', "
	@echo "${RESET}  /  |${PURPLE} 	    ,' ${RESET},'  ✨think✨   :     ✨die✨  ',${PURPLE} ', "
	@echo "${RESET}  \  /${PURPLE} 	   ,' ${RESET},'  ✨✨✨✨✨   :     ✨✨✨✨  ',${PURPLE} ', "
	@echo "${RESET}    \  ${PURPLE}	  ,' ${RESET},'.............., : ,..............',${PURPLE} ', "
	@echo "    ==   ,'  ${RESET}'.............   '.'   .............'${PURPLE}  ', "
	@echo "   (__)   ''''''''''''''''''';''';''''''''''''''''''' "
	@echo "                              '''  ${RESET}"

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;34m✨Philosophers successfully cleaned!✨\033[0m"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean art re