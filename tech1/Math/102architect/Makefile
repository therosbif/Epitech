NAME	= 102architect

CC	= gcc

RM	= rm -f

SRCS	= ./lib/my/my_compute_power_rec.c \
	  ./lib/my/my_getnbr.c \
	  ./source/main.c \
	  ./source/man_archi.c \
	  ./source/transformations.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
