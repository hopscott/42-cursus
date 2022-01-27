# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/01/25 17:19:10 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
INC_DIR = include
BIN_DIR = .

EXE =	$(BIN_DIR)/push_swap

SRC = 	$(SRC_DIR)/push_swap.c\
		$(SRC_DIR)/parsing.c\
		$(SRC_DIR)/stacks.c\
		$(SRC_DIR)/stacks_utils.c\
		$(SRC_DIR)/stacks_utils_algo.c\
		$(SRC_DIR)/operations.c\
		$(SRC_DIR)/algo.c\
		$(SRC_DIR)/algo_utils.c\

OBJ =	${SRC:.c=.o}

.c.o :
	cc $(CFLAGS) -o $@ -c $<

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

FNAME = libftprintf.a

PRINTF = lib/printf/libftprintf.a

${PRINTF} :
	make -C lib/printf -f Makefile

NAME = push_swap.a

${NAME} :	${OBJ} ${PRINTF} 
	cp $(PRINTF) .
	ar rcs $(NAME) $(OBJ)
	cc $(CFLAGS) $(PRINTF) $(NAME) -o $(EXE)

all:	${NAME}

clean:
	make -C lib/printf -f Makefile clean
	rm -rf $(OBJ)

fclean : clean
	make -C lib/printf -f Makefile fclean
	rm -rf $(NAME) $(FNAME) $(EXE)

re : fclean all

.PHONY : all clean fclean re
