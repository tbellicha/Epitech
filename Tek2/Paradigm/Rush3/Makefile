##
## EPITECH PROJECT, 2022
## B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
## File description:
## Makefile
##

UNAME := $(shell uname)

DIR			=	./

SRC			=	main.cpp \
				CheckParams.cpp\
				InfoModule.cpp \
				AllMonitors.cpp \
				IMonitorModule.cpp\
				NetworkModule.cpp\
				ComputeSFML.cpp\
				ncurse/ComputeNCurse.cpp\
				ncurse/printInfosNcurse.cpp\
				IMonitorDisplay.cpp

NAME    	=   MyGKrellm

CC			=	g++

CXXFLAGS	=	-std=c++20 -Wall -Wextra -lsfml-graphics \
				-lsfml-window -lsfml-system -lncurses -I ./


SRC_T		=	tests/tests_args.cpp\
				CheckParams.cpp\
				InfoModule.cpp \
				IMonitorModule.cpp\
				NetworkModule.cpp\
				ComputeSFML.cpp\
				ncurse/ComputeNCurse.cpp\
				ncurse/printInfosNcurse.cpp

ifeq ($(UNAME), Darwin)
	CXXFLAGS += -I/opt/homebrew/Cellar/sfml/2.5.1_1/include \
				-L/opt/homebrew/Cellar/sfml/2.5.1_1/lib
endif

TEST_BN		=	unit_tests

TFLAGS		=	-lcriterion --coverage

START_P		=	\033[0;95m

END			=	\033[0m

all:            $(NAME)

$(NAME):        $(SRC)
				$(CC) $(SRC) -o $(NAME)  $(CXXFLAGS)

clean:
				@rm -f $(OBJ)
				@rm -f $(OBJ_T)
				@rm -f **/*.gcno
				@rm -f **/*.gcna
				@rm -f **/*.gcda
				@rm -f *.gcno
				@rm -f *.gcna
				@rm -f *.gcda
				@echo -e "\n"
				@echo -e "$(START_P)CLEANED$(END)"

fclean:			clean
				@rm -f $(TEST_BN)
				@rm -f $(NAME)
				@echo -e "\n"
				@echo -e "$(START_P)FCLEANED$(END)"

re:             fclean all
				@echo -e "\n"
				@echo -e "$(START_P)REED$(END)"

tests_run:
				$(CC) -o $(TEST_N) $(TEST_FILES) $(SRC_T) $(CXXFLAGS) $(TFLAGS)
				./unit_tests --verbose
				gcovr --exclude-throw-branches \
				--exclude-unreachable-branches -e tests/ \
				-e main.cpp -b
				@echo -e "\n"
				@echo -e "$(START_P)TESTED$(END)"

debug:			CFLAGS += -g
debug: 			re
				@echo -e "\n"
				@echo -e "$(START_P)DEBUGGED$(END)"

.PHONY: all clean fclean re tests_run debug
