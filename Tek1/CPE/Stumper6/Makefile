##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC				=	src/main.c 				\
					src/grid.c 				\
					src/initialization.c	\
					src/tictactoe.c			\
					src/player_turn.c		\
					src/check_win.c			\
					src/check_draw.c		\
					src/check_trajectory.c	\
					src/destroy_game.c		\

OBJ				=	$(SRC:.c=.o)

NAME			=	tictactoe

CFLAGS			=	-Wall -Werror -Wshadow -Wextra -I include/

LDFLAGS			=	-L./lib -lmy

CC				=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(MAKE) -C lib/my/
			$(CC) $(OBJ) -o $(NAME) -L./lib/ -lmy -lm

unit_tests:
			@$(MAKE) -C lib/my/
			@$(MAKE) -C tests/

tests_run:
			@$(MAKE) unit_tests
			@./unit_tests
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

clean:
			rm -f $(OBJ)
			rm -f src/*.gcno
			rm -f src/*.gcda
			rm -f src/*.c.gcov

fclean:		clean
			rm -f $(NAME)
			make fclean -C lib/my/
			make fclean -C tests/
			rm -f lib/libmy.a

re:			fclean all

debug:			CFLAGS += -g
debug:			re

.PHONY:		all unit_tests tests_run clean fclean re
