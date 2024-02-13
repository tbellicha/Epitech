##
## EPITECH PROJECT, 2022
## B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
## File description:
## Makefile
##

SRC		=	$(shell find -type f -name "*.c")

OBJ		=	$(SRC:%.c=%.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re
