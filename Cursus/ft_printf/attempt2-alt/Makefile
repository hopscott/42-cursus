SRCS	= 	ft_printf.c\
			ft_printf_utils_str.c\
			ft_printf_utils_int.c\
			ft_printf_utils_uint.c\
			ft_printf_utils_ptr.c

OBJS	= 	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC	= 		cc

CFLAGS	= 	-Wall -Wextra -Werror

RM	= 		rm -f

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:	
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean	all

.PHONY:		all clean fclean re

