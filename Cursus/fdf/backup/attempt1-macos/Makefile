# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/02/27 20:39:31 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := fdf.a

# Dirs ==========================================

SRC_DIR := src
INC_DIR := include
LIB_DIR := lib
BIN_DIR := .

# Exes ==========================================

EXE :=	$(BIN_DIR)/fdf

# Compilation ====================================

CC := cc
LDFLAGS ?= -Lmlx -lmlx -framework OpenGL -framework AppKit
CFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR) -Imlx -g -fsanitize=address

# Src files ======================================

HEADERS := 	$(INC_DIR)/ft_printf.h\
			$(INC_DIR)/libft.h\
			$(INC_DIR)/fdf.h\

SRCS	:= 	$(SRC_DIR)/main.c\
	 		$(SRC_DIR)/maps.c\
			$(SRC_DIR)/tracing.c\
			$(SRC_DIR)/matrices.c\
			$(SRC_DIR)/rotations.c\
			$(SRC_DIR)/shifts.c\
			$(SRC_DIR)/keys.c\
			$(SRC_DIR)/lines.c\
			$(SRC_DIR)/fitting.c\
			$(SRC_DIR)/renders.c\

# Make all ========================================

all : $(NAME)

$(NAME): fdf

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

# Objects ========================================

OBJS :=	$(SRCS:.c=.o)

# Libs ==========================================

LIBFT := $(LIB_DIR)/libft/libft.a

PRINTF := $(LIB_DIR)/libftprintf/libftprintf.a

$(LIBFT) :
	make -C lib/libft -f Makefile

$(PRINTF) :
	make -C lib/libftprintf -f Makefile

# Recipes ========================================

fdf : $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(EXE)

# Cleanup ========================================

clean:
	make -C lib/libft -f Makefile clean
	make -C lib/libftprintf -f Makefile clean
	rm -rf $(OBJS)

fclean : clean
	make -C lib/libft -f Makefile fclean
	make -C lib/libftprintf -f Makefile fclean
	rm -rf $(EXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re
