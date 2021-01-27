NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	= ./lib/my/delim/my_strdup_dellim.c \
	  ./lib/my/delim/my_strlen_dellim.c \
	  ./lib/my/my_atoi.c \
	  ./lib/my/my_error.c \
	  ./lib/my/my_isalpha.c \
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
	  ./lib/my/my_strncmp.c \
	  ./lib/my/my_strtoarray.c \
	  ./source/builtin/my_cd.c \
	  ./source/builtin/my_env.c \
	  ./source/builtin/my_exit.c \
	  ./source/builtin/my_setenv.c \
	  ./source/builtin/my_unsetenv.c \
	  ./source/main.c \
	  ./source/not_builtin.c \
	  ./source/parent.c \
	  ./source/remove_tabs.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
