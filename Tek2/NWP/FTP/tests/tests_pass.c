/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** tests_pass
*/

#include "ftp.h"
#include <criterion/criterion.h>

Test(PASS, connecting_success)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {"password"};

    client->login = LOGIN_USER;
    client->password = strdup("");
    exec_pass(client, params);
    cr_assert_eq(client->login, LOGIN_CNCT);
}

Test(PASS, connecting_no_param)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {NULL};

    client->login = LOGIN_USER;
    exec_pass(client, params);
    cr_assert_eq(client->login, LOGIN_USER);
}

Test(PASS, connecting_no_user)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {"password"};

    client->login = LOGIN_NONE;
    exec_pass(client, params);
    cr_assert_eq(client->login, LOGIN_NONE);
}

Test(PASS, connecting_already_connected)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {"password"};

    client->login = LOGIN_CNCT;

    exec_pass(client, params);
    cr_assert_eq(client->login, LOGIN_CNCT);
}
