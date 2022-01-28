# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/01/28 13:41:13 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
INC_DIR = include
BIN_DIR = .

EXE =	$(BIN_DIR)/push_swap

SRC = 	$(SRC_DIR)/push_swap.c\
		$(SRC_DIR)/parsing.c\
		$(SRC_DIR)/parsing_utils.c\
		$(SRC_DIR)/parsing_utils_strings.c\
		$(SRC_DIR)/stacks.c\
		$(SRC_DIR)/stacks_utils.c\
		$(SRC_DIR)/stacks_utils_algo.c\
		$(SRC_DIR)/operations.c\
		$(SRC_DIR)/operations2.c\
		$(SRC_DIR)/operations3.c\
		$(SRC_DIR)/algo.c\
		$(SRC_DIR)/algo_utils.c\
		$(SRC_DIR)/algo_bins.c\

OBJ =	${SRC:.c=.o}

.c.o :
	cc $(CFLAGS) -o $@ -c $<

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

PRINTF = lib/printf/libftprintf.a

NAME = push_swap.a

all:	${NAME}

${NAME} :	${PRINTF} ${OBJ}
	ar rcs $(NAME) $(OBJ)
	cc $(CFLAGS) $(NAME) $(PRINTF) -o $(EXE)

${PRINTF} :
	make -C lib/printf -f Makefile

clean:
	make -C lib/printf -f Makefile clean
	rm -rf $(OBJ)

fclean : clean
	make -C lib/printf -f Makefile fclean
	rm -rf $(NAME) $(FNAME)

re : fclean all

.PHONY : all clean fclean re
