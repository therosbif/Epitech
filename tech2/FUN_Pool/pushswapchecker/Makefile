##
## EPITECH PROJECT, 2021
## B-FUN-300-LYN-3-1-pushswapchecker-jack.goodall
## File description:
## Makefile
##


NAME = pushswap_checker

SRCS =	$(shell find src -name "*.hs")

TEMPFILES = $(shell find . -name "*.o" -or -name "*.hi")

all:
	ghc $(SRCS) -o $(NAME) -O2

clean:
	rm -f $(TEMPFILES)
	make clean -C bonus/

fclean: clean
	rm -f $(NAME)
	make fclean -C bonus/

re: fclean all

bonus:
	make -C bonus/

.PHONY: all clean fclean re bonus
