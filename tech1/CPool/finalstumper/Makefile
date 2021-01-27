##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

NAME	= rush3

CC	= gcc

RM	= rm -f

SRCS	=	source/stumper.c \
		source/funcs.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I include/
CFLAGS += -Wall -Wextra -g -g3

LDFLAGS = -L lib -lmy

all: libmy $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

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
