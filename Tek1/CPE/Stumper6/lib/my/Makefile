##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c 					\
		my_putstr.c 					\
		my_put_nbr.c 					\
		my_str_isnum.c 					\
		concat_params.c 				\
		my_revstr.c 					\
		my_str_isprintable.c 			\
		my_str_isupper.c 				\
		my_strlen.c 					\
		my_compute_power_rec.c 			\
		my_show_word_array.c 			\
		my_strlowcase.c 				\
		my_compute_square_root.c 		\
		my_sort_int_array.c 			\
		my_strncat.c 					\
		my_find_prime_sup.c 			\
		my_strcapitalize.c 				\
		my_strncmp.c 					\
		my_getnbr.c 					\
		my_strcat.c 					\
		my_strncpy.c 					\
		my_isneg.c 						\
		my_strcmp.c 					\
		my_strstr.c 					\
		my_is_prime.c 					\
		my_strcpy.c 					\
		my_str_to_word_array.c 			\
		my_strdup.c 					\
		my_strupcase.c 					\
		my_str_isalpha.c 				\
		my_swap.c 						\
		my_str_islower.c 				\
		my_printf/my_put_binary_nbr.c	\
		my_printf/my_put_hexa_nbr.c		\
		my_printf/my_put_long_nbr.c		\
		my_printf/my_put_octal_nbr.c	\
		my_printf/my_put_octal_string.c	\
		my_printf/my_put_unsigned_int.c	\
		my_printf/space_in_flags.c		\
		my_printf/my_printf.c			\
		my_puterror.c					\
		my_itoa.c					\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS 	=	-Werror -Wextra -Wall -Wshadow

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@mv $(NAME) ../

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all