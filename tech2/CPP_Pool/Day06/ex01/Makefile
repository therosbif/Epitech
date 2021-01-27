##
## EPITECH PROJECT, 2021
## B-CPP-300-LYN-3-1-CPPD06-jack.goodall
## File description:
## Makefile
##

NAME	= my_convert_temp

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
