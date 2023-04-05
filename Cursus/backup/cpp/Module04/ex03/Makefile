# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/11/16 23:48:33 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := materia 

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
CPPFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR) -std=c++98 -g
LDFLAGS ?=

# Src files ======================================

HEADERS := 	$(INC_DIR)/AMateria.hpp\
			$(INC_DIR)/IMateriaSource.hpp\
			$(INC_DIR)/ICharacter.hpp\
			$(INC_DIR)/Cure.hpp\
			$(INC_DIR)/Ice.hpp\
			$(INC_DIR)/Character.hpp\
			$(INC_DIR)/MateriaSource.hpp

SRCS	:= 	$(SRC_DIR)/AMateria.cpp\
			$(SRC_DIR)/Cure.cpp\
			$(SRC_DIR)/Ice.cpp\
			$(SRC_DIR)/Character.cpp\
			$(SRC_DIR)/MateriaSource.cpp\
			$(SRC_DIR)/main.cpp

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
