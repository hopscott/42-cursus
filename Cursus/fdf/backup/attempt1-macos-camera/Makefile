# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/03/01 23:03:07 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
INC_DIR = include
BIN_DIR = .

LIBFT = lib/libft/libft.a
PRINTF = lib/libftprintf/libftprintf.a

NAME = fdf.a
EXE = fdf

SRC = 	$(SRC_DIR)/fdf.c\
	 	$(SRC_DIR)/map.c\
		$(SRC_DIR)/map_view.c\
	 	$(SRC_DIR)/tracing.c\

OBJ =	${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -Imlx -g -fsanitize=address

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

${NAME} :	all

all:	${LIBFT} ${PRINTF} ${OBJ}
	ar rcs $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(EXE)

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
	rm -rf $(NAME) $(EXE)

re : fclean all

.PHONY : all clean fclean re
