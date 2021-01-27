##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

NAME	= infin_add

CC	= gcc

RM	= rm -f

SRCS	=	source/main.c \
			source/add_sub.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I include/
CFLAGS += -Wall -Wextra -g

LDFLAGS = -L lib -lmy

all: libmy $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

libmy:
	make -C lib/my/

clean:
	$(RM) source/*.o
	make clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my/

re: fclean all

.PHONY: all clean fclean re
