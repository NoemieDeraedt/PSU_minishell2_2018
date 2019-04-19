##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	=	$(wildcard ./lib/my/*.c)	\
			$(wildcard ./src/*.c)

OBJS	=	$(SRCS:.c=.o)

DEL	=	$(wildcard vgcore*)	\
		$(wildcard ./*.o)	\
		$(wildcard ./src/*.o)	\
		$(wildcard ./lib/my/*.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libmy.a $(DEL)

re: fclean all