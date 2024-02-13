##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	$(wildcard src/*.c)\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ginger

CFLAGS	=	-I include/

SRC_T	=	src/mathematics_functions.c\
		src/error_manager.c\
		src/fractals_algorythm.c\
		tests/test.c

TEST_N	=	unit_tests

LIB	=	-L./lib/ -lmy

TFLAGS	=	-lcriterion --coverage -I include/

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

tests_run:
	$(MAKE) -C lib/my
	gcc -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

re: fclean all
