##
## EPITECH PROJECT, 2020
## CPE_matchstick_2019
## File description:
## Makefile
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	= ./lib/my/my_getnbr.c \
	  ./lib/my/my_isint.c \
	  ./lib/my/my_power.c \
	  ./lib/my/my_put_nbr.c \
	  ./lib/my/my_putchar.c \
	  ./lib/my/my_putstr.c \
	  ./lib/my/my_strcat.c \
	  ./lib/my/my_strcmp.c \
	  ./lib/my/my_strcpy.c \
	  ./lib/my/my_strdup.c \
	  ./lib/my/my_strlen.c \
	  ./lib/my/my_nlen.c \
	  ./source/main.c \
	  ./source/matches.c \
	  ./source/display.c \
	  ./source/map.c

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
