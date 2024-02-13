/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** testsParams
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "CheckParams.hpp"

static void redirect_all_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(testcheckParams, checkParams, .init = cr_redirect_stdout)
{
    check_params(2, NULL);
    cr_expect_stdout_eq_str("MyGKrellm\n-g\t\tDisplay graphical application\n-t\t\tDisplay text application\n-h\t\tPrint help\n");
}