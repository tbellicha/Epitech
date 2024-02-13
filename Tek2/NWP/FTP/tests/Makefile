##
## EPITECH PROJECT, 2022
## Projects
## File description:
## Makefile
##

DIR 	= 	../src/

SRC		=	$(DIR)commands1.c \
			$(DIR)commands2.c \
			$(DIR)commands3.c \
			tests_user.c \
			tests_pass.c \
			tests_cwd.c \

CC		=	gcc

OBJ		=	$(SRC:.c=.o)

NAME	=	unit_tests

CFLAGS	=	-Wall -Wshadow -Wextra -I ../include/ --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f ../$(NAME)

re:		fclean all