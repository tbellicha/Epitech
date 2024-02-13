##
## EPITECH PROJECT, 2022
## B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
## File description:
## Makefile
##

SRC			=	main.c \

SRC_T 		=	$(shell find -name "*.c") \

TEST_FILES 	=	$(shell find ./tests -name "*.c") \

NAME		=	my_nm

TEST_N		=	unit_tests

OBJ			=	$(SRC:%.c=%.o)

OBJTEST		=	$(SRC_T:%.c=%.o)

CFLAGS		=	-W -Wall -Wextra -Wshadow -I ../lib/my

LDFLAGS		=	-L../lib/ -lmy

T_FLAGS		=	-lcriterion --coverage

CC			=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LDFLAGS)

tests_run:
			$(CC) -o $(TEST_N) $(TEST_FILES) $(SRC_T) $(T_FLAGS) $(CFLAGS)
			./unit_tests --verbose
			gcovr --exclude-throw-branches --exclude-unreachable-branches \
			-e lib/tests/ -e tests/ -e $(SRC_DIR)main.c -b

clean:
			@find -type f -name '*.o' -delete
			@find -type f -name '*.gcda' -delete
			@find -type f -name '*.gcno' -delete
			@find -type f -name 'vgcore.*' -delete

fclean:		clean
			rm -f $(NAME)
			rm -f $(TEST_N)

re:			fclean all

debug: 		CFLAGS += -g
debug: 		re

.PHONY: 	all clean fclean re tests_run debug
