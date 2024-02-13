##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	do_op.c \
	    calc.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	do-op

CFLAGS	=	-Wall -Werror -Wshadow -Wextra -I../include

all:	$(NAME)

$(NAME):	$(OBJ)
	cd ../lib/my/ && make re
	cd ../do_op
	cc $(OBJ) -o $(NAME) $(CFLAGS) -L../lib/ -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all