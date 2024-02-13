##
## EPITECH PROJECT, 2022
## Projects
## File description:
## Makefile
##

DIR 	= 	../src/

SRC		=	$(DIR)Stockpile/stockpile.cpp \
			$(DIR)Pizza/pizza.cpp \
			$(DIR)Cook/cook.cpp \
			$(DIR)Kitchen/kitchen.cpp \
			$(DIR)Shell/shell.cpp \
			$(DIR)Message/message.cpp \
			$(DIR)Fork/fork.cpp \
			$(DIR)Logs/logs.cpp \
			$(DIR)plazza.cpp \
			pizza.cpp \
			stockpile.cpp \

CXX		=	g++

OBJ		=	$(SRC:%.cpp=%.o)

NAME	=	unit_tests

CXXFLAGS	=	-W -Wall -Wextra -Wshadow -pthread -lrt -I $(DIR) -I $(DIR)Cook/ -I $(DIR)Shell/ -I $(DIR)Kitchen/ -I $(DIR)Stockpile/ -I $(DIR)Pizza/ -I $(DIR)Logs/ -I $(DIR)Exception/ -I $(DIR)Message/ -I $(DIR)Fork/ -I $(DIR)Thread/ --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME) $(LDFLAGS)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f ../$(NAME)

re:		fclean all