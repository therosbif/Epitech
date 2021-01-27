NAME	= my_defender

CC	= gcc

RM	= rm -f

SRCS	= ./lib/my/my_atoi.c \
	  ./lib/my/my_error.c \
	  ./lib/my/my_isint.c \
	  ./lib/my/my_nlen.c \
	  ./lib/my/my_power.c \
	  ./lib/my/my_put_nbr.c \
	  ./lib/my/my_putchar.c \
	  ./lib/my/my_putstr.c \
	  ./lib/my/my_strcat.c \
	  ./lib/my/my_strcmp.c \
	  ./lib/my/my_strcpy.c \
	  ./lib/my/my_strdup.c \
	  ./lib/my/my_strlen.c \
	  ./source/init_alien.c \
	  ./source/animate.c \
	  ./source/move_alien.c \
	  ./source/main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/ -Wall -Wextra -g3

LDFLAGS = -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
