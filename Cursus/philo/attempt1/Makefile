# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/04/14 02:10:56 by scottwillis      ###   ########.fr        #
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
LDFLAGS ?= 
CFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR) -g -fsanitize=address

# Src files ======================================

HEADERS := 	$(INC_DIR)/philo.h\

SRCS	:= 	$(SRC_DIR)/main.c\
			$(SRC_DIR)/ft_atoi.c\

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
