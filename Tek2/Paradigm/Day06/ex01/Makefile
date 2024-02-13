##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

DIR		=		./

SRC     =       $(DIR)main.cpp \

OBJ     =       $(SRC:.cpp=.o)

NAME    =       my_convert_temp

CC		=		g++

CFLAGS  =       -std=c++20 -Wall -Wextra -Werror

# SRC_T	=		$(DIR)main.c \
# 				tests/tests.c

TEST_BN	=		unit_tests

TFLAGS	=		-lcriterion --coverage

all:            $(NAME)

$(NAME):        $(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)

re:             fclean all

# tests_run:
# 	$(MAKE) -C lib/my
# 	gcc -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
# 	./unit_tests
# 	gcovr --exclude tests/
# 	gcovr --exclude tests/ --branches

debug:			CFLAGS += -g
debug:			re