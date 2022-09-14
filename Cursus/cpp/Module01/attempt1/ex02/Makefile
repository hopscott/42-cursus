# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/09/14 15:59:38 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := brain

# Dirs ==========================================

SRC_DIR := src
LIB_DIR := lib
INC_DIR := includes
BIN_DIR := .

# Exes ==========================================

EXE := $(BIN_DIR)/$(NAME)

# Compilation ====================================

CC := c++
CPPFLAGS ?= -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR) -fsanitize=address -g
LDFLAGS ?=

# Src files ======================================

HEADERS := 	$(INC_DIR)/

SRCS	:= 	$(SRC_DIR)/main.cpp\

# Make all ========================================

all : $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $(CPPFLAGS) -o $@ $<

# Objects ========================================

OBJS := $(SRCS:.cpp=.o)

# Libs ==========================================

# Recipes ========================================

brain : $(OBJS)
	$(CC) $(CPPFLAGS) $^ $(LDFLAGS) -o $(EXE)

# Cleanup ========================================

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(EXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re
