# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/01/31 16:34:37 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
INC_DIR = include
BIN_DIR = .

CLIENT =	$(BIN_DIR)/client

SERVER =	$(BIN_DIR)/server

SRC = 	$(SRC_DIR)/client.c\

OBJ =	${SRC:.c=.o}

.c.o :
	cc $(CFLAGS) -o $@ -c $<

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

LIBFT = lib/libft/libft.a

PRINTF = lib/libftprintf/libftprintf.a

NAME = minitalk.a

all:	${NAME}

${NAME} :	${LIBFT} ${PRINTF} ${OBJ}
	ar rcs $(NAME) $(OBJ)
	cc $(CFLAGS) $(NAME) $(LIBFT) $(PRINTF) -o $(CLIENT)

${LIBFT} :
	make -C lib/libft -f Makefile

${PRINTF} :
	make -C lib/libftprintf -f Makefile

clean:
	make -C lib/libft -f Makefile clean
	make -C lib/libftprintf -f Makefile clean
	rm -rf $(OBJ)

fclean : clean
	make -C lib/libft -f Makefile fclean
	make -C lib/libftprintf -f Makefile fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
