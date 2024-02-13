##
## EPITECH PROJECT, 2022
## B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
## File description:
## Makefile
##

all:	nm objdump

nm:
		$(MAKE) -C ./lib/my/ -f Makefile -s
		$(MAKE) -C ./nm/ -f Makefile -s

objdump:
		$(MAKE) -C ./lib/my/ -f Makefile -s
		$(MAKE) -C ./objdump/ -f Makefile -s

clean:
		rm -f $(OBJ)
		$(MAKE) -C  ./lib/my/ clean -f Makefile -s
		$(MAKE) -C ./nm/ clean -f Makefile -s
		$(MAKE) -C ./objdump/ clean -f Makefile -s

fclean:	clean
		rm -f $(NAME)
		$(MAKE) -C ./lib/my/ fclean -f Makefile -s
		$(MAKE) -C ./nm/ fclean -f Makefile -s
		$(MAKE) -C ./objdump/ fclean -f Makefile -s

re:		fclean all

.PHONY: all nm objdump clean fclean re debug
