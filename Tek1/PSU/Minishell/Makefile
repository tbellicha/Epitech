##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)cd.c \
				$(DIR)switch.c \
				$(DIR)array.c \
				$(DIR)my_concat.c \
				$(DIR)env.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       mysh

CC		=		gcc

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all

debug:			CFLAGS += -g
debug:			re