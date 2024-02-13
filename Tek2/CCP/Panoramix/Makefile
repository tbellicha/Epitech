##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

DIR			=	src/

SRC			=	$(DIR)main.c \
				$(DIR)helper.c \
				$(DIR)init.c \
				$(DIR)args.c \
				$(DIR)villager.c \
				$(DIR)druid.c \
				$(DIR)str_isnum.c \

NAME		=	panoramix

CFLAGS		=	-Wall -Wshadow -Wextra -I./include/

CC			=	gcc

RM			=	rm -rf

OBJ			=	$(SRC:%.c=%.o)

LDFLAGS		= 	-lpthread

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
			@find -type f -name '*.o' -delete
			@find -type f -name '*.gcda' -delete
			@find -type f -name '*.gcno' -delete
			@find -type f -name 'vgcore.*' -delete

fclean:		clean
			$(RM) $(NAME)


tests_run:
			gcc -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
			./unit_tests
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

re:			fclean all

debug: 		CFLAGS += -g
debug: 		re

.PHONY: 	all clean fclean re debug
