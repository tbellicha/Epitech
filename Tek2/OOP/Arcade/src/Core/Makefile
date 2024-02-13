##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

SRC			=	main.cpp \
				libraries.cpp \
				events.cpp \
				menu.cpp \
				game.cpp \
				init.cpp \

NAME		=	arcade

CXXFLAGS	=	-W -Wall -Wextra -Wshadow -fno-gnu-unique

CXX			=	g++

OBJ			=	$(SRC:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(CFLAGS) -o $(NAME) $(LDFLAGS) -ldl
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
