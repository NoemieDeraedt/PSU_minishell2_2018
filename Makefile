NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	=   ./src/argv.c \
	  		./src/cd.c \
			./src/check.c \
			./src/env.c \
			./src/execute.c \
			./src/find.c \
			./src/launch_commands.c \
			./src/main.c \
			./src/manage_spaces.c \
			./src/pipe.c \
			./src/redir.c \
			./src/redir_left.c \
			./src/sep_redir.c \
			./src/setenv.c \
			./src/unsetenv.c \
			./src/write_error.c \
			./src/exec_builtin.c \
			./src/double_array.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/
	$(CC) $(OBJS) -o $(NAME) -L./lib/ -lmy $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

debug: CFLAGS += -g
debug: re

re: fclean all