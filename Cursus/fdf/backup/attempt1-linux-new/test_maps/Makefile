# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/04/01 19:06:11 by swillis          ###   ########.fr        #
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
LDFLAGS ?= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR) -I/usr/include -Imlx_linux -O3 -g -fsanitize=address

# Src files ======================================

HEADERS := 	$(INC_DIR)/ft_printf.h\
			$(INC_DIR)/libft.h\
			$(INC_DIR)/fdf.h\

SRCS	:= 	$(SRC_DIR)/main.c\
			$(SRC_DIR)/utils.c\
	 		$(SRC_DIR)/maps.c\
			$(SRC_DIR)/tracing.c\
			$(SRC_DIR)/tracing_rev.c\
			$(SRC_DIR)/matrices.c\
			$(SRC_DIR)/rotations.c\
			$(SRC_DIR)/shifts.c\
			$(SRC_DIR)/lines.c\
			$(SRC_DIR)/fitting.c\
			$(SRC_DIR)/renders.c\

BONUS_SRCS	:= 	$(SRC_DIR)/main.c\
			$(SRC_DIR)/utils_bonus.c\
	 		$(SRC_DIR)/maps.c\
			$(SRC_DIR)/tracing.c\
			$(SRC_DIR)/tracing_rev.c\
			$(SRC_DIR)/matrices.c\
			$(SRC_DIR)/rotations.c\
			$(SRC_DIR)/shifts.c\
			$(SRC_DIR)/keys_bonus.c\
			$(SRC_DIR)/keys_rotate_bonus.c\
			$(SRC_DIR)/keys_translate_bonus.c\
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

BONUS_OBJS :=	$(BONUS_SRCS:.c=.o)

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

bonus : $(BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(EXE)

# Cleanup ========================================

clean:
	make -C lib/libft -f Makefile clean
	make -C lib/libftprintf -f Makefile clean
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	make -C lib/libft -f Makefile fclean
	make -C lib/libftprintf -f Makefile fclean
	rm -rf $(EXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re
