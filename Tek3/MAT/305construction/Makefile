##
## EPITECH PROJECT, 2022
## 305construction
## File description:
## Makefile
##

NAME	= 	305construction

SRC		=	./305construction.py

SRC_T	=	./tests.py

TESTS_NAME	=	./unit_tests.py

CP		=	cp

CHMOD	=	chmod

EXEC_RIGHTS	=	+x

RM		=	rm -rf

all: $(NAME)

$(NAME):
	$(CP) $(SRC) ./$(NAME)
	$(CHMOD) $(EXEC_RIGHTS) $(NAME)

tests_run: all
	$(CP) $(SRC_T) $(TESTS_NAME)
	$(CHMOD) $(EXEC_RIGHTS) $(TESTS_NAME)
	pytest --cov=process --cov=main $(TESTS_NAME)

clean:
	$(RM) $(TESTS_NAME)
	$(RM) .coverage
	$(RM) .pytest_cache/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re