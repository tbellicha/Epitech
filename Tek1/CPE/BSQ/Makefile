##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR     =       src/

SRC     =       $(DIR)main.c \
				$(DIR)bsq.c \
				$(DIR)check_first_line.c \
				$(DIR)my_strlen.c \
				$(DIR)my_str_to_word_tab.c \
				$(DIR)my_getnbr.c \
				$(DIR)errors.c \
				$(DIR)my_put.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       bsq

CFLAGS  =       -Wall -Werror -Wshadow -Wextra -I ./include

all:    $(NAME)

$(NAME):	$(OBJ)
			cc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
