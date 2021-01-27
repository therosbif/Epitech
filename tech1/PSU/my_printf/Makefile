NAME	= libmy.a

CC	= gcc

RM	= rm -f

SRCS	= lib/my/concat_params.c \
	  lib/my/my_compute_power_rec.c \
	  lib/my/my_compute_square_root.c \
	  lib/my/my_convert.c \
	  lib/my/my_delete_nodes.c \
	  lib/my/my_getnbr.c \
	  lib/my/my_params_to_list.c \
	  lib/my/my_printf.c \
	  lib/my/my_put_nbr.c \
	  lib/my/my_putchar.c \
	  lib/my/my_putstr.c \
	  lib/my/my_rev_list.c \
	  lib/my/my_revstr.c \
	  lib/my/my_show_word_array.c \
	  lib/my/my_sort_int_array.c \
	  lib/my/my_sort_list.c \
	  lib/my/my_str_isalpha.c \
	  lib/my/my_str_islower.c \
	  lib/my/my_str_isnum.c \
	  lib/my/my_str_isprintable.c \
	  lib/my/my_str_isupper.c \
	  lib/my/my_strcat.c \
	  lib/my/my_strcmp.c \
	  lib/my/my_strcpy.c \
	  lib/my/my_strdup.c \
	  lib/my/my_strlen.c \
	  lib/my/my_strncat.c \
	  lib/my/my_strncmp.c \
	  lib/my/my_strncpy.c \
	  lib/my/my_strstr.c \
	  lib/my/output.c \
	  lib/my/sum_stdarg.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)
	 cp lib/my/my.h ./include

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
