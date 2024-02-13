/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** 
*/

#include <criterion/criterion.h>

int *my_str_islower(char const *str);

Test (my_str_islower, test_is_lower)
{
    cr_assert_eq(my_str_islower("jds"), 1);
    cr_assert_eq(my_str_islower("123456"), 0);
    cr_assert_eq(my_str_islower("..."), 0);
    cr_assert_eq(my_str_islower("{"), 0);
    cr_assert_eq(my_str_islower(""), 1);  
}
