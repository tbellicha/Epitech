##
## EPITECH PROJECT, 2022
## B-PSU-400-NAN-4-1-malloc-tanguy.bellicha
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)malloc.c \
				$(DIR)block.c \
				$(DIR)find_block.c \
				$(DIR)free.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy_malloc.so

CC		=		gcc

CFLAGS  =       -I include/ -fPIC -Wall -Wshadow -Werror

all:            $(NAME)

$(NAME):        $(OBJ)
				$(CC) -shared -o $(NAME) $(OBJ) $(CFLAGS)

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)

re:             fclean all