##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC     =       postfix.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       eval_expr

CFLAGS  =       -Wall -Werror -Wshadow -Wextra -I include/

all:    $(NAME)

$(NAME):        $(OBJ)
		cd lib/my/ && make re
		cd ../../
		gcc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
