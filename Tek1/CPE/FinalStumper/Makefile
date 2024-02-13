##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	rush3.c \
		main.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

CFLAGS	=	-Wall -Werror -Wshadow -Wextra -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		cd lib/my/ && make re
		cd ../../
		cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
