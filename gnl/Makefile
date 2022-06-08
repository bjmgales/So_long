NAME= get_next_line
CC= gcc
CFLAGS= -Wall -Wextra -Werror -D BUFFER_SIZE=10
RM=rm -f
SRCS=../ft_printf/ft_printf.c \
../ft_printf/ft_printf_util.c \
../ft_printf/ft_putnbr_hex.c \
../ft_printf/ft_putnbr.c \
../ft_printf/ft_itoa.c \
get_next_line.c \
get_next_line_utils.c \

OBJS=${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re