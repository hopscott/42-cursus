# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/09/14 15:37:59 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := zombie

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

HEADERS := 	$(INC_DIR)/Zombie.hpp\

SRCS	:= 	$(SRC_DIR)/main.cpp\
			$(SRC_DIR)/Zombie.cpp\
			$(SRC_DIR)/zombieHorde.cpp\

# Make all ========================================

all : $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $(CPPFLAGS) -o $@ $<

# Objects ========================================

OBJS := $(SRCS:.cpp=.o)

# Libs ==========================================

# Recipes ========================================

zombie : $(OBJS)
	$(CC) $(CPPFLAGS) $^ $(LDFLAGS) -o $(EXE)

# Cleanup ========================================

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(EXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re
