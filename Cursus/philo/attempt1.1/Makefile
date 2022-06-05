# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/04/21 15:09:22 by scottwillis      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name ==========================================

NAME := philo.a

# Dirs ==========================================

PHILO_DIR := philo
SRC_DIR := $(PHILO_DIR)
INC_DIR := $(PHILO_DIR)
BIN_DIR := $(PHILO_DIR)

# Exes ==========================================

EXE :=	$(BIN_DIR)/philo

# Compilation ====================================

CC := cc
LDFLAGS ?= -pthread
CFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR) -g -fsanitize=thread

# Src files ======================================

HEADERS := 	$(INC_DIR)/philo.h\

SRCS	:= 	$(SRC_DIR)/main.c\

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
