/*
** EPITECH PROJECT, 2020
** test_my_strncmp
** File description:
** 
*/

#include <criterion/criterion.h>

char *my_strncmp(char const *s1, char const *s2, int n);

Test (my_strncmp, compare_n_char_of_two_strings)
{
    char s1[] = "Hello World";
    char s2[] = "Hella";
    int n = 4;

    my_strncmp(s1, s2, n);
    cr_assert_eq(my_strncmp(s1, s2, n), 0);
}



