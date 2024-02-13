##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile for unit_test
##

SRC		=	tests.c \
			test_victory.c	\
			../src/grid.c \
			../src/initialization.c \
			../src/destroy_game.c \
			../src/check_win.c	\
			../src/check_trajectory.c

OBJ     =	$(SRC:.c=.o)

NAME	=	unit_tests

CFLAGS  =	-Wall -Werror -Wshadow -Wextra -I ../include/ --coverage -lcriterion

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -L../lib/ -lmy
			mv unit_tests ../

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f ../$(NAME)
			rm -f *.gcno
			rm -f *.gcda
			rm -f .c.gcov

re:			fclean all
