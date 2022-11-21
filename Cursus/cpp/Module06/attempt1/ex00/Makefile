# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/11/21 01:00:52 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := interns 

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
CPPFLAGS ?= -Wall -Wextra -Werror -Wno-unused -Wconversion -I$(INC_DIR) -std=c++98
LDFLAGS ?=

# Src files ======================================

HEADERS := 	$(INC_DIR)/Bureaucrat.hpp\
			$(INC_DIR)/AForm.hpp\
			$(INC_DIR)/ShrubberyCreationForm.hpp\
			$(INC_DIR)/RobotomyRequestForm.hpp\
			$(INC_DIR)/PresidentialPardonForm.hpp\
			$(INC_DIR)/Intern.hpp\

SRCS	:= 	$(SRC_DIR)/main.cpp\
			$(SRC_DIR)/Bureaucrat.cpp\
			$(SRC_DIR)/AForm.cpp\
			$(SRC_DIR)/ShrubberyCreationForm.cpp\
			$(SRC_DIR)/RobotomyRequestForm.cpp\
			$(SRC_DIR)/PresidentialPardonForm.cpp\
			$(SRC_DIR)/Intern.cpp\

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