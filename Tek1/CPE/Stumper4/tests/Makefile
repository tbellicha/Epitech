##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for units tests
##


SRC	=   ../src/battle.c \
		../src/display.c \
		../src/parsing.c \
		../src/pokemon.c \
		../src/utils.c \
		../src/files.c \
		test_battle.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS =   -L../lib/my -lmy

CFLAGS	=	-I ../includes -I ../lib/my/includes -lcriterion --coverage

NAME	=	units_tests

$(NAME):	$(OBJ)
	$(MAKE) -C ../lib/my
	gcc $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	find . ../ -name "*.gcno" -delete
	find . ../ -name "*.gcda" -delete

all:	$(NAME)

re:	fclean all
