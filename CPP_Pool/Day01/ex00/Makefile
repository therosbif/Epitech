##
## EPITECH PROJECT, 2021
## B-CPP-300-LYN-3-1-CPPD01-jack.goodall
## File description:
## Makefile
##

NAME	= z

CC	= gcc

RM	= rm -f

SRCS	= ./z.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -std=gnu11 -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
