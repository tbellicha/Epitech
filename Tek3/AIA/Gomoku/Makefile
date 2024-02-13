NAME = pbrain-gomoku-ai

SRC_T	=	./tests/tests.py

TESTS_NAME	=	./unit_tests.py

$(NAME):
	@cp src/main.py pbrain-gomoku-ai
	@chmod +x pbrain-gomoku-ai

.PHONY: all
all: $(NAME)

.PHONY: re
re: clean all

.PHONY: clean
clean:
	@rm -f pbrain-gomoku-ai
	@rm -f .coverage
	@rm -f $(TESTS_NAME)
	@rm -rf .pytest_cache/

.PHONY: fclean
fclean: clean

.PHONY: tests_run_unit
tests_run_unit: re
	@echo "* Unit testing *"
	@cp $(SRC_T) $(TESTS_NAME)
	@chmod +x $(TESTS_NAME)
	@pytest --cov=src.command $(TESTS_NAME)

.PHONY: tests_run_funct
tests_run_funct: re
	@echo "* Functional testing *"
	@sh tests.sh

.PHONY: tests_run
tests_run: re tests_run_unit tests_run_funct
