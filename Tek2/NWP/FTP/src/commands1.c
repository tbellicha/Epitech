/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** commands
*/

#include "ftp.h"

void exec_user(client_t *client, char **params)
{
    if (params == NULL || params[0] == NULL) {
        dprintf(client->fd, "430 Invalid username or password\n");
        return;
    }
    if (client->login == LOGIN_CNCT) {
        dprintf(client->fd, "230 Already logged in.\n");
        return;
    }
    if (client->username)
        free(client->username);
    client->username = strdup(params[0]);
    if (strcmp(client->username, "Anonymous"))
        client->login = LOGIN_USER;
    else
        client->login = LOGIN_CNCT;
    dprintf(client->fd, "331 User name okay, need password.\r\n");
}

void exec_pass(client_t *client, char **params)
{
    if (client->login == LOGIN_CNCT) {
        dprintf(client->fd, "230 Already logged in.\n");
        return;
    } else if (client->login == LOGIN_NONE) {
        dprintf(client->fd, "332 Need account for login.\n");
        return;
    }
    if (params == NULL || params[0] == NULL) {
        dprintf(client->fd, "430 Invalid username or password\n");
        return;
    }
    client->login = LOGIN_CNCT;
    if (client->password)
        free(client->password);
    client->password = strdup(params[0]);
    dprintf(client->fd, "230 User logged in, proceed.\n");
}

void exec_cwd(client_t *client, char **params)
{
    if (params == NULL || params[0] == NULL) {
        dprintf(client->fd, "550 Syntax error in parameters or arguments.\n");
        return;
    }
    if (client->login == LOGIN_CNCT) {
        if (chdir(params[0]) == -1) {
            dprintf(client->fd, "550 Failed to change directory.\n");
            return;
        }
        dprintf(client->fd, "250 Requested file action okay, completed.\n");
    } else {
        dprintf(client->fd, "530 Not logged in.\n");
    }
}

void exec_cdup(client_t *client, char **params)
{
    if (client->login == LOGIN_CNCT) {
        if (chdir("..") == -1) {
            dprintf(client->fd, "550 Failed to change directory.\n");
            return;
        };
        dprintf(client->fd, "250 Requested file action okay, completed.\n");
        return;
    }
    dprintf(client->fd, "530 Not logged in.\n");
}

void exec_quit(client_t *client, char **params)
{
    if (client->login == LOGIN_CNCT) {
        dprintf(client->fd, "221 User logged out.\n");
        client->login = LOGIN_DISC;
    } else {
        dprintf(client->fd, "530 Not logged in.\n");
    }
}
