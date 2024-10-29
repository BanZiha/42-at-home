NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c				\
	doubly_linked_list.c	\
	stack_commands_1.c		\
	stack_commands_2.c		\
	stack_commands_3.c		\
	greedy_sort_1.c			\
	greedy_sort_2.c			\
	greedy_sort_3.c			\
	push_swap_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re