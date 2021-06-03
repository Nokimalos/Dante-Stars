##
## EPITECH PROJECT, 2021
## my_defender
## File description:
## Makefile
##

SRC		=	./src/main.c	\
			./src/read_map.c	\
			./src/str_to_tab.c	\
			./src/utility_function.c	\
			./src/algorithm.c	\
			./src/error_handling.c	\
			./src/maze.c	\

OBJ		=	$(SRC:.c=.o)

NAME		=	solver

CPPFLAGS	= -I include/

CFLAGS	=	-W -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f *~
	rm -f *.html

fclean: clean
	rm -f $(NAME)
	rm -f lib/libmy.a
	rm -f lib/my/libmy.a

re:	fclean all

.PHONY: all clean fclean re
