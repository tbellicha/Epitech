##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC     =   main.c \
			src/display.c \
			src/game_init.c \
			src/game_loop.c \
			src/manage_errors.c \
			src/parsing.c \
			src/player_turn.c \
			src/utils.c

OBJ     =	$(SRC:.c=.o)

NAME    =	hangman

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
	make fclean -C ./tests
	rm -f $(NAME)

re:	fclean  all

tests_run:
	$(MAKE) -C tests/
	./tests/units_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
