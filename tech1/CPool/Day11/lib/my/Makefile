##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC = *.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

NAME2 = my.h

all:
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
	cp $(NAME2) ../../include

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f ../$(NAME)

re:	fclean all
