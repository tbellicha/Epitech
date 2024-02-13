##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)animations.c \
				$(DIR)check.c \
				$(DIR)end.c \
				$(DIR)events.c \
				$(DIR)files.c \
				$(DIR)get.c \
				$(DIR)initialization.c \
				$(DIR)jump.c \
				$(DIR)linked_list.c \
				$(DIR)map.c \
				$(DIR)rect.c \
				$(DIR)score.c \
				$(DIR)window.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_runner

CC		=		gcc

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all