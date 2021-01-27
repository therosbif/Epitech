##
## EPITECH PROJECT, 2019
## CPE_pushswap_2019
## File description:
## Makefile
##

NAME	= push_swap

CC	= gcc

RM	= rm -f

SRCS	= ./lib/my/my_atoi.c \
	  ./lib/my/p_ab.c \
	  ./lib/my/s_abc.c \
	  ./source/main.c \
	  ./lib/my/my_putstr.c \
	  ./lib/my/my_put_nbr.c \
	  ./lib/my/my_strcmp.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Ofast
#CFLAGS += -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
