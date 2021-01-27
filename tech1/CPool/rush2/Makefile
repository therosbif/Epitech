##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make doop
##

SRC	=	main.c \
		rush2.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	rush2

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I include/ -L lib/ -l my

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
