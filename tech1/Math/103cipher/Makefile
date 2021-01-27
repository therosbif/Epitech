##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## Makefile
##

NAME	= 103cipher

CC	= gcc

RM	= rm -f

SRCS	= ./source/display/display_decryption.c \
	  ./source/display/display_encryption.c \
	  ./source/display/display_key_matrix/display_key_matrix_decryption.c \
	  ./source/display/display_key_matrix/display_key_matrix_encryption.c \
	  ./source/error_handling.c \
	  ./source/main.c \
	  ./source/make_inverse.c \
	  ./source/make_key.c \
	  ./source/make_message.c \
	  ./source/make_result.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -g3
CFLAGS += -Wall -Wextra

LDFLAGS = -l m

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
