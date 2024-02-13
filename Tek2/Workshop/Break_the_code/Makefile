##
## EPITECH PROJECT, 2022
## GROUNDHOG
## File description:
## Makefile
##

NAME = exo

all: $(NAME)

SRC_T	=	./tests.py

TESTS_NAME	=	./unit_tests.py

RM		=	rm -rf

$(NAME):
	cp exo.py exo
	chmod +x $(NAME)

tests_run: all
	cp $(SRC_T) $(TESTS_NAME)
	chmod +x $(TESTS_NAME)
	pytest --cov=process --cov=results --cov=main $(TESTS_NAME) -v

clean:
	$(RM) $(TESTS_NAME)
	$(RM) .coverage
	$(RM) .pytest_cache/

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMEBONUS)

re: fclean all

bonus: $(NAMEBONUS)

.PHONY: all clean fclean re