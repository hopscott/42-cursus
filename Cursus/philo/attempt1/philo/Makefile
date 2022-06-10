# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <swillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/06/10 15:14:47 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := philo.a

# Dirs ==========================================

PHILO_DIR := .
SRC_DIR := $(PHILO_DIR)
INC_DIR := $(PHILO_DIR)
BIN_DIR := $(PHILO_DIR)

# Exes ==========================================

EXE :=	$(BIN_DIR)/philo

# Compilation ====================================

CC := cc
LDFLAGS ?= -pthread
CFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR) # -g -fsanitize=thread

# Src files ======================================

HEADERS := 	$(INC_DIR)/philo.h\

SRCS	:= 	$(SRC_DIR)/actions.c\
			$(SRC_DIR)/checks.c\
			$(SRC_DIR)/ft_atoi.c\
			$(SRC_DIR)/init.c\
			$(SRC_DIR)/main.c\
			$(SRC_DIR)/routines.c\
			$(SRC_DIR)/utils.c\

# Make all ========================================

all : $(NAME)

$(NAME): philo

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

# Objects ========================================

OBJS :=	$(SRCS:.c=.o)

# Libs ==========================================

# Recipes ========================================

philo : $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(EXE)

# Cleanup ========================================

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(EXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re
