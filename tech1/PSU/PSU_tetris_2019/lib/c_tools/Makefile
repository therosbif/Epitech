##
## EPITECH PROJECT, 2019
## PSU_tetris_2019
## File description:
## Makefile
##

SRC	=	./my_atoi.c \
		./my_error.c \
		./my_isint.c \
		./my_nlen.c \
		./my_power.c \
		./my_put_nbr.c \
		./my_putchar.c \
		./my_putstr.c \
		./my_strcat.c \
		./my_strcmp.c \
		./my_strcpy.c \
		./my_strdup.c \
		./my_strlen.c \
		./base_convert.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../../include -g

LIB_NAME	=	libc_tools.a

all: $(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	mv $(LIB_NAME) ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(LIB_NAME)

re: fclean all
