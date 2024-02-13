##
## EPITECH PROJECT, 2022
## B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
## File description:
## Makefile
##

SRC			=	sfmlLibrary.cpp

NAME		=	arcade_sfml.so

CXXFLAGS	=	-W -Wall -Wextra -fPIC

CXX			=	g++

OBJ			=	$(SRC:%.cpp=%.o)

LDFLAGS 	= 	-lsfml-window -lsfml-graphics -lsfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) -fPIC -shared -o $(NAME) $(OBJ) $(LDFLAGS)
			mv $(NAME) ../../

clean:
			@find -type f -name '*.o' -delete
			@find -type f -name '*.gcda' -delete
			@find -type f -name '*.gcno' -delete
			@find -type f -name 'vgcore.*' -delete

fclean:		clean
			rm -f ../../$(NAME)

re:			fclean all

debug: 		CFLAGS += -g
debug: 		re

.PHONY: 	all clean fclean re debug
