##
## EPITECH PROJECT, 2021
## B-CPP-300-LYN-3-1-CPPD01-jack.goodall
## File description:
## Makefile
##

NAME	= menger_face

CC	= gcc

RM	= rm -f

SRCS	= ./bitmap_header.c \
	  ./drawing.c \
	  ./main.c \
	  ./menger.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra -g3

LDFLAGS = -lm

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
