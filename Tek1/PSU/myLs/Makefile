##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)my_ls_without_flag.c \
				$(DIR)switch_flags.c \
				$(DIR)control.c \
				$(DIR)display.c \
				$(DIR)my_get.c \
				$(DIR)sort_file.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_ls

CFLAGS  =       -Wall -Wshadow -Wextra -I./include

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my/

re:             fclean all