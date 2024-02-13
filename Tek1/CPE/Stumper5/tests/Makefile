##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for units tests
##


SRC	=			tests_errors.c \
				tests_file.c \
				../src/parsing.c \
				../src/manage_errors.c

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
