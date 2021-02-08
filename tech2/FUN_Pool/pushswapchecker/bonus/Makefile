##
## EPITECH PROJECT, 2021
## B-FUN-300-LYN-3-1-pushswapchecker-jack.goodall
## File description:
## Makefile
##

NAME = ../pushswap

SRCS =	$(shell find src -name "*.hs") \
		../src/Parser.hs \
		../src/Sort.hs

TEMPFILES = $(shell find . -name "*.o" -or -name "*.hi")

all:
	ghc $(SRCS) -o $(NAME)

clean:
	rm -f $(TEMPFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
