NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= crs
AR			= ar

SRCS		= ft_printf.c		\
			ft_check_format.c	\
			ft_putptr.c			\
			ft_puthex.c			\
			ft_putchar.c		\
			ft_putnbr.c			\
			ft_putstr.c			\
			ft_putunbr.c

OBJS		= ${SRCS:.c=.o}

all			: $(NAME)

%.o			: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		: $(OBJS)
			${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean		:
			rm -rf ${OBJS} 

fclean		: clean
			rm -rf ${NAME}

re			: fclean all

.PHONY		: all clean fclean re