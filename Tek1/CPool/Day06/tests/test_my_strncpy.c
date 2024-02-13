/*
** EPITECH PROJECT, 2020
** test_my_strncpy
** File description:
** 
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test (my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[5] = {0};
    
    my_strncpy(dest, "Hello World", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test (my_strncpy, copy_five_characters_in_array)
{
    char dest[5] = {'0'};

    my_strncpy(dest, "12345", 5);
    cr_assert_str_eq(dest, "12345");
}
Test (my_strncpy, copy_eight_characters_in_empty_array)
{
    char dest[8] = {0};

    my_strncpy(dest, "Hello World", 8);
    cr_assert_str_eq(dest, "Hello Wo");
}

Test (my_strncpy, copy_eight_specials_characters_in_empty_array)
{
    char dest[10] = {0};

    my_strncpy(dest, ", ; : ! p ", 8);
    cr_assert_str_eq(dest, ", ; : ! ");
}
