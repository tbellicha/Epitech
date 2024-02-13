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
    char *argv[] = {"./my_ginger", "-f", "tests/maps/map.txt", "-m", "2"};

    ginger_setup(argv);
}
