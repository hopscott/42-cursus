# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/10/25 01:03:25 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := scavtrap

# Dirs ==========================================

SRC_DIR := src
INC_DIR := includes
OBJ_DIR := build
LIB_DIR := lib
BIN_DIR := .

# Exes ==========================================

EXE := $(BIN_DIR)/$(NAME)

# Compilation ====================================

CC := c++
CPPFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR) -std=c++98
LDFLAGS ?=

# Src files ======================================

HEADERS := 	$(INC_DIR)/ClapTrap.hpp\
			$(INC_DIR)/ScavTrap.hpp

SRCS	:= 	$(SRC_DIR)/main.cpp\
			$(SRC_DIR)/ClapTrap.cpp\
			$(SRC_DIR)/ScavTrap.cpp

# Make all ========================================

all : $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

# Objects ========================================

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Libs ==========================================

# Recipes ========================================

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $^ $(LDFLAGS) -o $(EXE)

# Cleanup ========================================

clean:
	rm -rf $(OBJS) $(OBJ_DIR)

fclean : clean
	rm -rf $(EXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re
