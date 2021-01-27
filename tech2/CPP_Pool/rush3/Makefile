NAME	= MyGKrellm

CC	= g++

RM	= rm -f

SRCS	= ./src/Cpu.cpp \
	  ./src/Date.cpp \
	  ./src/Hostname.cpp \
	  ./src/KernelOS.cpp \
	  ./src/MonitorDisplay.cpp \
	  ./src/Network.cpp \
	  ./src/Ram.cpp \
	  ./src/main.cpp	\
	  ./src/GraphWindow.cpp	\
		src/print_ncurses.cpp


OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/
CPPFLAGS += -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
