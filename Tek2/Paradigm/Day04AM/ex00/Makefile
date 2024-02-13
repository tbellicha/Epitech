##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC     = main.c

OBJ     = $(SRC:.c=.o)

NAME    = z

CC      = gcc

CFLAGS  = -std=gnu17 -Wall -Wextra

all: $(NAME)

$(NAME):    $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re