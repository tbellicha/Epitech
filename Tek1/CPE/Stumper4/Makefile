##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC		=	main.c \
			src/battle.c \
			src/display.c \
			src/parsing.c \
			src/pokemon.c \
			src/files.c \
			src/utils.c

OBJ     =	$(SRC:.c=.o)

NAME    =	pokemon

LDFLAGS	=	-Llib/my -lmy

CFLAGS	=	-Wall -Wextra -Wshadow -I includes -I lib/my/includes

all:	$(NAME)

$(NAME):	$(OBJ) lib/my/libmy.a
	gcc $(OBJ) $(LDFLAGS) -o $(NAME)

lib/my/libmy.a:
		make -C ./lib/my

clean:
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my
	make fclean -C tests
	rm -f $(NAME)

re:	fclean  all

tests_run:
	$(MAKE) -C tests/
	./tests/units_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
