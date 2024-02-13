/*
** EPITECH PROJECT, 2020
** test_my_revstr
** File description:
** 
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test (my_revstr, reverse)
{
    char str1[] = "Hello";
    
    my_revstr(str1);
    cr_assert_str_eq(str1, "olleH");

    char str2[] = "0123456789";
    my_revstr(str2);
    cr_assert_str_eq(str2, "9876543210");

    char str3[] = "";
    my_revstr(str3);
    cr_assert_str_eq(str3, "");
}

