##
## EPITECH PROJECT, 2022
## BS
## File description:
## Makefile
##

DIR		=	src/

SRC		=	$(DIR)main.c \
			$(DIR)server.c \
			$(DIR)helper.c \
			$(DIR)commands1.c \
			$(DIR)commands2.c \
			$(DIR)commands3.c \
			$(DIR)array.c \
			$(DIR)port.c \
			$(DIR)client.c \

OBJ		=	$(SRC:.c=.o)

NAME	=	myftp

CC		=	gcc

RM		=	rm -rf

CFLAGS	=	-Wall -Wshadow -Wextra -I./include/

NAME_T	=	unit_tests

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)
			$(RM) *.gcno
			$(RM) *.gcda
			$(RM) *.gcov
			$(RM) $(DIR)*.gcda
			$(RM) $(DIR)*.gcno
			$(RM) tests/*.o
			$(RM) tests/*.gcda
			$(RM) tests/*.gcno

fclean:		clean
			$(RM) $(NAME)
			$(RM) tests/$(NAME_T)

re:			fclean all

tests_run:
			$(MAKE) -C tests/
			./tests/unit_tests
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

debug:		CFLAGS += -g
debug:		re
