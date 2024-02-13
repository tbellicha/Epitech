##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

SRC			=	sdlLibrary.cpp

NAME		=	arcade_sdl2.so

CXXFLAGS	=	-W -Wall -Wextra -fPIC

CXX			=	g++

OBJ			=	$(SRC:%.cpp=%.o)

LDFLAGS		= 	-lSDL2 -lSDL2_ttf -lSDL2_image

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
