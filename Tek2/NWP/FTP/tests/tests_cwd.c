/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** tests_cwd
*/

#include "ftp.h"
#include <criterion/criterion.h>

Test(CWD, cwd_easy)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {"/home"};

    client->login = LOGIN_CNCT;
    exec_cwd(client, params);
    cr_assert_str_eq(getcwd(NULL, 0), "/home");
}

Test(CWD, cwd_no_path)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {NULL};
    char *old_path = getcwd(NULL, 0);

    client->login = LOGIN_CNCT;
    exec_cwd(client, params);
    cr_assert_str_eq(getcwd(NULL, 0), old_path);
}

Test(CWD, cwd_no_params)
{
    client_t* client = malloc(sizeof(client_t));
    char **params = NULL;
    char *old_path = getcwd(NULL, 0);

    client->login = LOGIN_CNCT;
    exec_cwd(client, params);
    cr_assert_str_eq(getcwd(NULL, 0), old_path);
}

Test(CWD, cwd_login_state_user)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {"/home"};
    char *old_path = getcwd(NULL, 0);

    client->login = LOGIN_USER;
    exec_cwd(client, params);
    cr_assert_str_eq(getcwd(NULL, 0), old_path);
}

Test(CWD, cwd_login_state_none)
{
    client_t* client = malloc(sizeof(client_t));
    char *params[1] = {"/home"};
    char *old_path = getcwd(NULL, 0);

    client->login = LOGIN_NONE;
    exec_cwd(client, params);
    cr_assert_str_eq(getcwd(NULL, 0), old_path);
}