NAME = minishell

SRCS = builtins/echo.c \
		builtins/exit.c \
		builtins/pwd.c \
		builtins/cd.c \
		builtins/env.c \
		utils/error_handling.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft
FSANTIZE = -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


libft:
	make -C libft

clean:
	rm -f $(OBJS) 
	make -C libft clean

fclean: clean
	rm -f $(NAME) 
	rm -f libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re