##
## EPITECH PROJECT, 2019
## CGP_my_screensaver_bootstrap_2019
## File description:
## Makefile
##

NAME	= my_screensaver

CC	= gcc

RM	= rm -f

SRCS	= ./source/draw.c \
	  ./source/framebuffer.c \
	  ./source/main.c \
	  ./source/screensavers.c \
	  ./source/polygone.c \
	  ./source/help.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -l csfml-graphics -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
