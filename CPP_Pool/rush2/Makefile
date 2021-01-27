##
## EPITECH PROJECT, 2021
## TEST
## File description:
## test
##

NAME = factory

TYPE = cpp

SRCS = $(wildcard ./Wrap/*.$(TYPE)) \
		$(wildcard ./Workstation/*.$(TYPE)) \
		$(wildcard ./Toys/*.$(TYPE)) \
		$(wildcard ./ElfS/*.$(TYPE)) \
		main.cpp

OBJS = $(SRCS:.$(TYPE)=.o)

CXXFLAGS += -Wall -Wextra -Werror -g3

RM = rm -f

CC = g++

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

purge:
	$(RM) vgcore.*

clean: purge
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all clean fclean re test
