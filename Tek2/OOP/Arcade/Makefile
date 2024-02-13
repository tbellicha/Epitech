##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

all:	core games graphicals

DIR_CORE	=	./src/Core/

DIR_GAMES	=	./lib/Games/

DIR_GRAPH	=	./lib/Graphic/

core:
		$(MAKE) -C $(DIR_CORE) -f Makefile -s

games:
		$(MAKE) -C $(DIR_GAMES)Pacman/ -f Makefile -s
		$(MAKE) -C $(DIR_GAMES)Nibbler/ -f Makefile -s

graphicals:
		$(MAKE) -C $(DIR_GRAPH)SDL2/ -f Makefile -s
		$(MAKE) -C $(DIR_GRAPH)SFML/ -f Makefile -s
		$(MAKE) -C $(DIR_GRAPH)nCurses/ -f Makefile -s

clean:
		$(MAKE) -C $(DIR_CORE) clean -f Makefile -s
		$(MAKE) -C $(DIR_GAMES)Pacman/ clean -f Makefile -s
		$(MAKE) -C $(DIR_GAMES)Nibbler/ clean -f Makefile -s
		$(MAKE) -C  $(DIR_GRAPH)SDL2/ clean -f Makefile -s
		$(MAKE) -C  $(DIR_GRAPH)SFML/ clean -f Makefile -s
		$(MAKE) -C  $(DIR_GRAPH)nCurses/ clean -f Makefile -s

fclean:	clean
		$(MAKE) -C $(DIR_CORE) fclean -f Makefile -s
		$(MAKE) -C $(DIR_GAMES)Pacman/ fclean -f Makefile -s
		$(MAKE) -C $(DIR_GAMES)Nibbler/ fclean -f Makefile -s
		$(MAKE) -C  $(DIR_GRAPH)SDL2/ fclean -f Makefile -s
		$(MAKE) -C  $(DIR_GRAPH)SFML/ fclean -f Makefile -s
		$(MAKE) -C  $(DIR_GRAPH)nCurses/ fclean -f Makefile -s

re:		fclean all

.PHONY: all core games graphicals clean fclean re debug
