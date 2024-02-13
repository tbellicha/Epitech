##
## EPITECH PROJECT, 2022
## COMMUNISTE
## File description:
## Makefile
##


NAME_TEST = tests

SRC_TEST = Test.hs

NAME	=	pushswap_checker

SRC		=	Main.hs

FLAG	=	-Wall -W

RM		=	rm -rf

CC		=	ghc

all:		$(NAME)

$(NAME):
		$(CC) -o $(NAME) $(SRC)

# To comment before pushing
# tests_run:
# 		$(CC) -o $(NAME_TEST) $(SRC_TEST) -fhpc
# 		./$(NAME_TEST)
# 		hpc report $(NAME_TEST)

clean:
		$(RM) *.o
		$(RM) *.hi
		$(RM) *.tix
		$(RM) .hpc/
		$(RM) $(NAME_TEST)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re name 
