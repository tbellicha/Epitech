/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** tests_user
*/

#include "ftp.h"
#include <criterion/criterion.h>

Test(USER, connecting_success)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {"toto"};

    client->login = LOGIN_NONE;
    exec_user(client, params);
    cr_assert_eq(client->login, LOGIN_USER);
}

Test(USER, connecting_no_param)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {NULL};

    client->login = LOGIN_NONE;
    exec_user(client, params);
    cr_assert_eq(client->login, LOGIN_NONE);
}

Test(USER, connecting_already_connected)
{
    int fd = 42;
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {NULL};
    char buff[BUFFER_SIZE];

    client->login = LOGIN_CNCT;
    // client->fd = fd;
    // read(fd, buff, 0);

    exec_user(client, params);
    cr_assert_eq(client->login, LOGIN_CNCT);
}

Test(USER, connecting_anonymous)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {"Anonymous"};

    client->login = LOGIN_NONE;

    exec_user(client, params);
    cr_assert_eq(client->login, LOGIN_CNCT);
}