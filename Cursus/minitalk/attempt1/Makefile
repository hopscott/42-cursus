# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:15:41 by swillis           #+#    #+#              #
#    Updated: 2022/02/07 19:58:26 by swillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
INC_DIR = include
BIN_DIR = .

UTILSRC = 		$(SRC_DIR)/base_conversion.c\
				$(SRC_DIR)/utils.c\
				$(SRC_DIR)/utils2.c\

UTILOBJ =		${UTILSRC:.c=.o}

CLIENT =		$(BIN_DIR)/client

CLIENTSRC = 	$(SRC_DIR)/client.c\

CLIENTOBJ =		${CLIENTSRC:.c=.o}

SERVER =		$(BIN_DIR)/server

SERVERSRC = 	$(SRC_DIR)/server.c\

SERVEROBJ =		${SERVERSRC:.c=.o}

.c.o :
	cc $(CFLAGS) -o $@ -c $<

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

LIBFT = lib/libft/libft.a

PRINTF = lib/libftprintf/libftprintf.a

${NAME} :	all

all:	${LIBFT} ${PRINTF} ${UTILOBJ} ${SERVEROBJ} ${CLIENTOBJ}
	cc $(CFLAGS) $(UTILOBJ) $(SERVEROBJ) $(LIBFT) $(PRINTF) -o $(SERVER)
	cc $(CFLAGS) $(UTILOBJ) $(CLIENTOBJ) $(LIBFT) $(PRINTF) -o $(CLIENT)

${LIBFT} :
	make -C lib/libft -f Makefile

${PRINTF} :
	make -C lib/libftprintf -f Makefile

clean:
	make -C lib/libft -f Makefile clean
	make -C lib/libftprintf -f Makefile clean
	rm -rf $(UTILOBJ) $(SERVEROBJ) $(CLIENTOBJ)

fclean : clean
	make -C lib/libft -f Makefile fclean
	make -C lib/libftprintf -f Makefile fclean
	rm -rf $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re
