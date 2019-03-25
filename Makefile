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

VALG	=	$(wildcard vgcore*)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libmy.a $(VALG)

re: fclean all

.PHONY: all clean fclean re
