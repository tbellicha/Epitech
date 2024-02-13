##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)files.c \
				$(DIR)move.c \
				$(DIR)get.c \
				$(DIR)check.c \
				$(DIR)switch.c \
				$(DIR)window.c \
				$(DIR)map.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_sokoban

CC		=		gcc

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy -lncurses

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all