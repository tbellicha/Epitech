/*
** EPITECH PROJECT, 2020
** test_my_str_isalpha
** File description:
** 
*/

#include <criterion/criterion.h>

int *my_str_isalpha(char const *str);

Test (my_str_isalpha, string_with_only_numbers)
{
    cr_assert_eq(my_str_isalpha("12"), 0);
}

Test (my_str_isalpha, string_with_only_caps)
{
    cr_assert_eq(my_str_isalpha("AZERTY"), 1);
}

Test (my_str_isalpha, string_with_numbers_and_caps)
{
    cr_assert_eq(my_str_isalpha("AZ123"), 0);
}

Test (my_str_isalpha, null_string)
{
    cr_assert_eq(my_str_isalpha(""), 1);
}

