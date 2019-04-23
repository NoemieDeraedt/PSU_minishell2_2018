RM	= rm -f

SRCS	= ./my/error_message.c \
	  ./my/my_compute_power_rec.c \
	  ./my/my_error.c \
	  ./my/my_isneg.c \
	  ./my/my_printf.c \
	  ./my/my_put_nbr.c \
	  ./my/my_putchar.c \
	  ./my/my_putstr.c \
	  ./my/my_revstr.c \
	  ./my/my_show_word_array.c \
	  ./my/my_strcat.c \
	  ./my/my_strconcat.c \
	  ./my/my_strcpy.c \
	  ./my/my_strdup.c \
	  ./my/my_strlen.c \
	  ./my/my_strncat.c \
	  ./my/my_strncpy.c \
	  ./my/my_swap.c \
	  ./my/number_in_array.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./../include/
CFLAGS += -Wall -Wextra

all: $(OBJS)
	ar rc libmy.a $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) libmy.a

re: fclean all