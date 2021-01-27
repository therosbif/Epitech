##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

NAME	= eval_expr

CC	= gcc

RM	= rm -f

SRCS	=	source/funcs.c \
			source/summands.c \
			source/opps.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I include/
CFLAGS += -Wall -Wextra -g

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
