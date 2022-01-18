# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/01/18 17:46:53 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a

VPATH = srcs

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

all = $(NAME)

$(LIBFT) :
	make -C libft -f Makefile

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : push_swap.h libft/libft.h

.c.o :
	cc $(CFLAGS) -I. -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C libft -f Makefile clean

fclean : clean
	make -C libft -f Makefile fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
