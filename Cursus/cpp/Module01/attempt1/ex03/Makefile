# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/09/15 13:39:42 by scottwillis      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := violence

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

HEADERS := 	$(INC_DIR)/Weapon.hpp\
			$(INC_DIR)/HumanA.hpp\

SRCS	:= 	$(SRC_DIR)/main.cpp\
			$(SRC_DIR)/weapon.cpp\
			$(SRC_DIR)/humanA.cpp\

# Make all ========================================

all : $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $(CPPFLAGS) -o $@ $<

# Objects ========================================

OBJS := $(SRCS:.cpp=.o)

# Libs ==========================================

# Recipes ========================================

violence : $(OBJS)
	$(CC) $(CPPFLAGS) $^ $(LDFLAGS) -o $(EXE)

# Cleanup ========================================

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(EXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re
