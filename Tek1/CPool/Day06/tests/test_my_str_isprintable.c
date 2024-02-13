/*
** EPITECH PROJECT, 2020
** test_my_str_isprintable
** File description:
** 
*/

#include <criterion/criterion.h>

int *my_str_isprintable(char const *str);

Test (my_str_isprintable, null)
{
    cr_assert_eq(my_str_isprintable(""), 1);
    cr_assert_eq(my_str_isprintable('\t'), 0);
    cr_assert_eq(my_str_isprintable(""), 1);
    cr_assert_eq(my_str_isprintable(8), 0);
    
}
