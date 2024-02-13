/*
** EPITECH PROJECT, 2020
** test_rush.c
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "rush3.h"

void rush3(char *buff);

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(rush3, rush1_1_single, .init = redirect_all_stdout)
{
    char *buff = "o\n";
    rush3(buff);
    cr_assert_stdout_eq_str("[rush1-1] 1 1\n");
}

Test(rush3, rush1_1_horizontal, .init = redirect_all_stdout)
{
    char *buff = "o--o\n";

    rush3(buff);
    cr_assert_stdout_eq_str("[rush1-1] 4 1\n");
}

Test(rush3, rush1_1_vertical, .init = redirect_all_stdout)
{
    char *buff = "o\no\no\no\n";

    rush3(buff);
    cr_assert_stdout_eq_str("[rush1-1] 1 4\n");
}

Test(rush3, rush1_1_regular, .init = redirect_all_stdout)
{
    char *buff = "o-o\n| |\n| |\no-o";

    rush3(buff);
    cr_assert_stdout_eq_str("[rush1-1] 3 3\n");
}

Test(rush3, rush_1_2_single, .init = redirect_all_stdout)
{
    char *buff = "*\n";
    rush3(buff);
    cr_assert_stdout_eq_str("[rush1-2] 1 1\n");
}

Test(rush3, rush_1_2_horizontal, .init = redirect_all_stdout)
{
    char *buff = "****\n";
    rush3(buff);
    cr_assert_stdout_eq_str("[rush1-2] 4 1\n");
}

Test(rush3, rush_1_2_vertical, .init = redirect_all_stdout)
{
    char *buff = "*\n*\n*\n*\n";
    rush3(buff);
    cr_assert_stdout_eq_str("[rush1-2] 1 4\n");
}