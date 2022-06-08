NAME= solong
CC= gcc
CFLAGS= -Wall -Wextra -D BUFFER_SIZE=1
RM=rm -f
SRCS=./so_long.c \
./ft_printf/ft_printf.c \
./ft_printf/ft_printf_util.c \
./ft_printf/ft_putnbr_hex.c \
./ft_printf/ft_putnbr.c \
./ft_printf/ft_itoa.c \
./gnl/get_next_line.c \
./gnl/get_next_line_utils.c \
./map_check.c \
./move.c \
./move2.c \
./zero.c \

OBJS=${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -lmlx -framework OpenGL -framework Appkit -lz -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re