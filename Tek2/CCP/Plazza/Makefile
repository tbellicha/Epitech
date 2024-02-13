##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

DIR			=	src/

SRC			=	$(DIR)plazza.cpp \
				$(DIR)main.cpp \
				$(DIR)Cook/cook.cpp \
				$(DIR)Shell/shell.cpp \
				$(DIR)Kitchen/kitchen.cpp \
				$(DIR)Stockpile/stockpile.cpp \
				$(DIR)Pizza/pizza.cpp \
				$(DIR)Logs/logs.cpp \
				$(DIR)Thread/thread.cpp \
				$(DIR)Message/message.cpp \
				$(DIR)Fork/fork.cpp \

NAME		=	plazza

CXXFLAGS	=	-W -Wall -Wextra -Wshadow -pthread -lrt -I include -I src/ -I src/Cook/ -I src/Shell/ -I src/Kitchen/ -I src/Stockpile/ -I src/Pizza/ -I src/Logs/ -I src/Exception/ -I src/Thread/ -I src/Message/ -I src/Fork/

CXX			=	g++

OBJ			=	$(SRC:%.cpp=%.o)

RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME) $(LDFLAGS)

clean:
			@find -type f -name '*.o' -delete
			@find -type f -name '*.gcda' -delete
			@find -type f -name '*.gcno' -delete
			@find -type f -name 'vgcore.*' -delete

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

tests_run:
			$(MAKE) -C tests/
			./tests/unit_tests
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

debug: 		CXXFLAGS += -g
debug: 		re

.PHONY: 	all clean fclean re debug
