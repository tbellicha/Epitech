##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC     =       infin_add.c \
				main.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       infin_add

CFLAGS  =       -Wall -Werror -Wshadow -Wextra -I/include

all:    $(NAME)

$(NAME):        $(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) -lmy -L./lib/my

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
