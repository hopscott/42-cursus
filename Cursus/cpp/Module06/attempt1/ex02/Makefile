# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/11/27 20:09:05 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := identify 

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
CPPFLAGS ?= -Wall -Wextra -Werror -Wno-unused -Wconversion -I$(INC_DIR) -std=c++98 -g
LDFLAGS ?=

# Src files ======================================

HEADERS := 	$(INC_DIR)/Base.hpp\
			$(INC_DIR)/A.hpp\
			$(INC_DIR)/B.hpp\
			$(INC_DIR)/C.hpp\
			$(INC_DIR)/functions.hpp

SRCS	:= 	$(SRC_DIR)/main.cpp\
			$(SRC_DIR)/functions.cpp

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
