#==============================================================
# DECLARATION
#==============================================================

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./lib/libft.a

#==============================================================
# FILES
#==============================================================

SRCS =	$(wildcard ./built_in/*.c) \
		$(wildcard ./env/*.c) \
		$(wildcard ./execute/none_builtin/*.c) \
		$(wildcard ./execute/run/*.c) \
		$(wildcard ./expand/step/*.c) \
		$(wildcard ./expand/variable/*.c) \
		$(wildcard ./expand/wildcard/*.c) \
		$(wildcard ./redirect/*.c) \
		$(wildcard ./shell/*.c) \
		$(wildcard ./syntax/input/*.c) \
		$(wildcard ./syntax/token/*.c) \
		$(wildcard ./tree/*.c) \
		$(wildcard ./token/*.c) \
		$(wildcard ./utils/*.c) \
		$(wildcard ./visual/*.c) \
		$(wildcard ./signal/*.c) \
		main2.c

OBJS = $(SRCS:.c=.o)

#==============================================================
# BUILD COMMAND
#==============================================================

all: lib $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -lreadline
	
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