##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)check.c \
				$(DIR)lists.c \
				$(DIR)main.c \
				$(DIR)push_and_switch.c \
				$(DIR)rotate.c \

OBJ     =       $(SRC:.c=.o)

CC     =       gcc

NAME    =       push_swap

CFLAGS  =       -Wall -Wshadow -Wextra -I./lib/my -I./include

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all
