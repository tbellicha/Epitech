##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile compilation
##

DIR		=		sources/

SRC     =       $(DIR)my_put_nbr.c \
				$(DIR)my_putchar.c \
				$(DIR)my_putstr.c \
				$(DIR)my_strlen.c \
				$(DIR)my_getnbr.c \
				$(DIR)my_putnbr_base.c \
				$(DIR)my_convert_base.c \
				$(DIR)my_printf.c \
				$(DIR)my_switch_file.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

CFLAGS  =       -Wall -Wshadow -Wextra -I/includes

all:            $(NAME)

$(NAME):        $(OBJ)
				ar rc $(NAME) $(OBJ)

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)

re:             fclean all