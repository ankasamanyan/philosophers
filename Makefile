# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 08:40:39 by ankasamanya       #+#    #+#              #
#    Updated: 2022/10/28 15:48:30 by akasaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c atoi.c 
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
		@$(CC) $(OBJ) -o $(NAME) -fsanitize=address -g
	@echo "\n\033[0;35m✨Philosophers successfully compiled!✨"
	@echo "	"
	@echo "${RESET}  (\      	    ${RESET},..........   ..........,${PURPLE} "
	@echo "${RESET}  \ \ ${PURPLE}          ,..${RESET},' ✨✨✨✨ '.'  ✨✨✨  ',${PURPLE}.., "
	@echo "${RESET}   \ \ ${PURPLE}        ,' ${RESET},'  ✨eat ✨  :   ✨die✨  ',${PURPLE} ', "
	@echo "${RESET}   /  | ${PURPLE}      ,' ${RESET},'  ✨sleep✨  :    ✨die✨  ',${PURPLE} ', "
	@echo "${RESET}   \  /${PURPLE}      ,' ${RESET},'  ✨think✨   :     ✨die✨  ',${PURPLE} ', "
	@echo "${RESET}     \ ${PURPLE}	    ,' ${RESET},'  ✨✨✨✨✨   :     ✨✨✨✨  ',${PURPLE} ', "
	@echo "     == ${PURPLE}   ,' ${RESET},'.............., : ,..............',${PURPLE} ', "
	@echo "    (__)  ,'  ${RESET}'.............   '.'   .............'${PURPLE}  ', "
	@echo "           ''''''''''''''''''';''';''''''''''''''''''' "
	@echo "                               '''  ${RESET}"

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;34m✨Philosophers successfully cleaned!✨\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "	"
	@echo "${RESET}  (\      	    ${RESET},..........   ..........,${PURPLE} "
	@echo "${RESET}  \ \ ${PURPLE}          ,..${RESET},'          '.'          ',${PURPLE}.., "
	@echo "${RESET}   \ \ ${PURPLE}        ,' ${RESET},'            :            ',${PURPLE} ', "
	@echo "${RESET}   /  | ${PURPLE}      ,' ${RESET},'             :             ',${PURPLE} ', "
	@echo "${RESET}   \  /${PURPLE}      ,' ${RESET},'              :              ',${PURPLE} ', "
	@echo "${RESET}     \ ${PURPLE}	    ,' ${RESET},'               :               ',${PURPLE} ', "
	@echo "     == ${PURPLE}   ,' ${RESET},'.............., : ,..............',${PURPLE} ', "
	@echo "    (__)  ,'  ${RESET}'.............   '.'   .............'${PURPLE}  ', "
	@echo "           ''''''''''''''''''';''';''''''''''''''''''' "
	@echo "                               '''  ${RESET}"

re: fclean all

.PHONY: all clean fclean art re
