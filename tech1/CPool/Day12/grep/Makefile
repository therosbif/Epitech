##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

NAME	= grep

TEST	= ../tests/tests_cat.c

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ../include/
CFLAGS += -Wall -Wextra

LDFLAGS = -L ../lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

libmy:
	make -C ../lib/my/

tests_run:
	gcc -o unit_test cat_func.c $(TEST) --coverage -lcriterion $(CFLAGS) $(LDFLAGS)
	./unit_test

clean:
	$(RM) $(OBJS) *.g*
	make clean -C ../lib/my/

fclean: clean
	$(RM) $(NAME) unit_test

re: fclean all

.PHONY: all clean fclean re
