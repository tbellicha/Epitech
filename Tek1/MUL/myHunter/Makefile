##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		= 		src/

SRC     =       $(DIR)main.c \
				$(DIR)events.c \
				$(DIR)window.c \
				$(DIR)bird_animations.c \
				$(DIR)rect_horizontal_bird.c \
				$(DIR)rect_vertical_bird.c \
				$(DIR)rect_top_corner_bird.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_hunter

CFLAGS  =       -Wall -Wshadow -Wextra -I./include

all:    $(NAME)

$(NAME):	$(OBJ)
			make re -C lib/my/
			gcc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy -lcsfml-graphics -lcsfml-system

clean:
		rm -f $(OBJ)
		make clean -C lib/my/

fclean: clean
		rm -f $(NAME)
		make fclean -C lib/my/

re:	fclean all

.PHONY: all clean fclean re