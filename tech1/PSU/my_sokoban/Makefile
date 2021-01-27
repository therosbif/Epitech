##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

NAME	= my_sokoban

CC	= gcc

RM	= rm -f

SRCS	= ./source/main.c \
		  ./source/my_strlen.c \
		  ./source/my_strcpy.c \
		  ./source/measure.c \
		  ./source/my_strcmp.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I include/
CFLAGS += -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -g3 $(OBJS) -o $(NAME) $(LDFLAGS) -l ncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
