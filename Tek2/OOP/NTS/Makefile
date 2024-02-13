##
## EPITECH PROJECT, 2022
## NanoTekSpice
## File description:
## Makefile
##

SRC			=	Main.cpp \
				Component/AComponent.cpp \
				Component/SpecialComponent.cpp \
				Component/BasicComponent.cpp \
				Component/Factory.cpp \
				Parser/Parser.cpp \
				NanoTekSpice.cpp \

SRC_T 		=	$(shell find -name "*.cpp") \

TEST_FILES 	=	$(shell find ./tests -name "*.cpp") \

NAME		=	nanotekspice

TEST_N		=	unit_tests

OBJ			=	$(SRC:.cpp=.o)

OBJTEST		=	$(SRC_T:.cpp=.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow\
				-I ./ -I Component -I Parser -I Exception

T_FLAGS		=	-lcriterion --coverage

CC			=	g++

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CXXFLAGS) -o $(NAME)

tests_run:
			$(CC) -o $(TEST_N) $(TEST_FILES) $(SRC_T) $(T_FLAGS) $(CXXFLAGS)
			./unit_tests --verbose
			gcovr --exclude-throw-branches --exclude-unreachable-branches \
			-e lib/tests/ -e tests/ -e $(SRC_DIR)main.c -b

clean:
			@find -type f -name '*.o' -delete
			@find -type f -name '*.gcda' -delete
			@find -type f -name '*.gcno' -delete
			@find -type f -name 'vgcore.*' -delete

fclean:		clean
			rm -f $(NAME)
			rm -f $(TEST_N)

re:			fclean all

debug: 		CFLAGS += -g
debug: 		re

.PHONY: 	all clean fclean re tests_run debug
