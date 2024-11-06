#==============================================================
# DECLARATION
#==============================================================

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FSANTIZE = -fsanitize=address -g3

LIBFT = ./lib/libft.a

#==============================================================
# FILES
#==============================================================

SRCS =	$(wildcard ./utils/*.c) \
		$(wildcard ./parse/syntax/before/*.c) \
		$(wildcard ./parse/syntax/after/*.c) \
		$(wildcard ./parse/token/*.c) \
		$(wildcard ./parse/tree/*.c) \
		$(wildcard ./execute/cmd/*.c) \
		$(wildcard ./execute/path/*.c) \
		$(wildcard ./execute/polish/*.c) \
		$(wildcard ./execute/run/*.c) \
		$(wildcard ./env/*.c) \
		$(wildcard ./built_in/*.c) \
		$(wildcard ./utils/*.c) \
		main2.c

OBJS = $(SRCS:.c=.o)

#==============================================================
# BUILD COMMAND
#==============================================================

all: lib $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ -lreadline $(LIBFT)
	
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	make -C lib

clean:
	rm -f $(OBJS) 
	make -C lib clean

fclean: clean
	rm -f $(NAME) 
	make -C lib fclean

re: fclean all

.PHONY: all bonus lib clean fclean re