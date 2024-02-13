/*
** EPITECH PROJECT, 2020
** test_my_strstr
** File description:
** 
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test (my_strstr, find_a_string_into_a_string)
{
    char str[] = "Hello World";
    char to_find[] = "llo";

    my_strstr(str, to_find);
    cr_assert_str_eq(my_strstr(str, to_find), "llo World");
}
