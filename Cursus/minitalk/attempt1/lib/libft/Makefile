SRCS	=	ft_atoi.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlen.c\
			ft_strlcpy.c\

OBJS	= 	${SRCS:.c=.o}

NAME	= libft.a

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean	all

.PHONY:		all clean fclean re

