# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/11/15 23:21:18 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := animals 

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

HEADERS := 	$(INC_DIR)/AAnimal.hpp\
			$(INC_DIR)/Dog.hpp\
			$(INC_DIR)/Cat.hpp\
			$(INC_DIR)/WrongAnimal.hpp\
			$(INC_DIR)/WrongCat.hpp\
			$(INC_DIR)/Brain.hpp

SRCS	:= 	$(SRC_DIR)/main.cpp\
			$(SRC_DIR)/AAnimal.cpp\
			$(SRC_DIR)/Dog.cpp\
			$(SRC_DIR)/Cat.cpp\
			$(SRC_DIR)/WrongAnimal.cpp\
			$(SRC_DIR)/WrongCat.cpp\
			$(SRC_DIR)/Brain.cpp

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
