##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make doop
##

SRC	=	do_op/do_op.c\
		do_op/my_getnbr.c\
		do_op/my_putchar.c\
		do_op/my_put_nbr.c\
		do_op/my_putstr.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	do-op

CFLAGS	=	-Wall -Wextra -I ../include

LIBMY	=	libmy.a	

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBMY)
	gcc -o $(NAME) $(OBJ)

$(LIBMY):
	make -C ../lib/my

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	make fclean -C ../lib/my/
	rm -f $(NAME)

re: fclean all
