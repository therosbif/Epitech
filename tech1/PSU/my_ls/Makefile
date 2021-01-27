##
## EPITECH PROJECT, 2019
## project
## File description:
## .
##

NAME	= my_ls

CC	= gcc

RM	= rm -f

SRCS	= ./source/array.c \
	  ./source/flags.c \
	  ./source/main.c \
	  ./source/my_putstr.c \
	  ./source/stringmod.c \
	  ./source/l_flag.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
