#==============================================================
# DECLARATION
#==============================================================

# https://docs.google.com/presentation/d/1rcPz4ajolZtAr2M0I41reJHuVogjdWeL/edit?usp=sharing&ouid=117690636457397361031&rtpof=true&sd=true

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
		$(wildcard ./signal/*.c) \

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