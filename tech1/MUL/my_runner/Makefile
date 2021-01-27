##
## EPITECH PROJECT, 2020
## MUL_my_runner_2019
## File description:
## Makefile
##

NAME	= my_runner

CC	= gcc

RM	= rm -f

SRCS	= ./source/init.c \
  		  ./source/main.c \
		  ./source/init_ent.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -l csfml-graphics -l csfml-system -l csfml-window

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
