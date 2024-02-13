##
## EPITECH PROJECT, 2022
## B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
## File description:
## Makefile
##

DIR			=	ex00/

SRC			=	$(DIR)Toy.cpp \
				$(DIR)Picture.cpp \

OBJ			=	$(SRC:.cpp=.o)

CC			=	g++

CXXFLAGS	=	-std=c++17 -Wall -Wextra -Werror -I ./ex00/ $(TFLAGS)

SRC_T		=	tests/tests_toy.cpp

OBJ_T		=	$(SRC_T:.cpp=.o)

TEST_BN		=	unit_tests

TFLAGS		=	-lcriterion --coverage

clean:
				rm -f $(OBJ)
				rm -f $(OBJ_T)
				rm -f **/*.gcno
				rm -f **/*.gcna
				rm -f **/*.gcda

fclean:			clean
				rm -f $(TEST_BN)

tests_run:		$(OBJ) $(OBJ_T)
				$(CC) $(CXXFLAGS) $(OBJ_T) $(OBJ) -o $(TEST_BN)
				./unit_tests --verbose
				gcovr --exclude tests/ --branches

debug:			CFLAGS += -g