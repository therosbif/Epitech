##
## EPITECH PROJECT, 2021
## B-CPP-300-LYN-3-1-CPPD03-jack.goodall
## File description:
## Makefile
##

NAME	= libstring.a

RM	= rm -f

SRCS	= ./append.c \
	  ./assign.c \
	  ./compare.c \
	  ./find.c \
	  ./my_strcat.c \
	  ./my_strcmp.c \
	  ./my_strcpy.c \
	  ./my_strdup.c \
	  ./my_strlen.c \
	  ./string.c \
	  ./my_strstr.c \
	  ./insert.c \
	  ./to_int.c \
	  ./split.c \
	  ./join.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
