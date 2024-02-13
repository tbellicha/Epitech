/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** TU
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/proto.h"

Test(stumper, one, .init=cr_redirect_stdout)
{
    fractals_start(1, "##@#.", "..@..");
    cr_assert_stdout_eq_str("##\n#.\n");
}

Test(stumper, error, .init=cr_redirect_stdout)
{
    int outpout = 0;
    char **argv = malloc(sizeof(char *) * 4);

    argv[0] = my_strdup("./fractals");
    argv[1] = my_strdup("1");
    argv[2] = my_strdup("###@#.#@###");
    argv[3] = my_strdup("...@...@...");
    outpout = check_error(4, argv);
    cr_assert_eq(outpout, 0);
}
