##
## EPITECH PROJECT, 2019
## project
## File description:
## .
##

NAME	= fractals

NAME_TEST = unit_test

CC	= gcc

RM	= rm -f

SRCS	= ./source/arr_len.c \
	  ./source/copy_over.c \
	  ./source/error.c \
	  ./source/fractal.c \
	  ./source/is_int.c \
	  ./source/main.c \
	  ./source/my_atoi.c \
	  ./source/my_putstr.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
