##
## EPITECH PROJECT, 2019
## tetris
## File description:
## Makefile
##

NAME	= tetris

CC	=	gcc

RM	=	rm -f

SRCS	=	./source/main.c \
			./source/print_help.c \
			./source/debug_mode.c \
			./source/init_curse.c \
			./source/get_flags.c \
			./source/print_tetrimino_name.c \
			./source/print_tetrimino_fline_info.c \
			./source/print_tetrimino.c \
			./source/tetris.c \
			./source/create_tetrimino.c \
			./source/add_tetrimino.c \
			./source/create_default_list.c \
			./source/cycle.c \
			./source/list_len.c \
			./source/mv_rect.c \
			./source/free_lists.c \
			./source/draw_window.c \
			./source/get_delay.c \
			./source/remove_line.c \
			./source/game_over.c \
			./source/rotate.c \
			./source/set_game_info.c \
			./source/display_game_info.c \
			./source/int_to_str.c \
			./source/handle_input.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS =	-I ./include/
CFLAGS +=	-Wall -Wextra -g

LDFLAGS	=	-l ncurses -L./lib -l c_tools

all: $(NAME)

$(NAME): $(OBJS) build_lib
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

build_lib:
	make -C ./lib/c_tools

clean:
	$(RM) $(OBJS)
	make clean -C ./lib/c_tools

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/c_tools

re: fclean all

.PHONY: all clean fclean re
