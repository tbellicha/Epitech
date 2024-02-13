/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** commands
*/

#include "ftp.h"

void exec_dele(client_t *client, char **params)
{
    if (client->login == LOGIN_CNCT) {
        if (params == NULL || params[0] == NULL) {
            dprintf(client->fd,
                "501 Syntax error in parameters or arguments.\n");
            return;
        }
        if (remove(params[0]) == -1) {
            dprintf(client->fd, "550 Failed to delete file.\n");
            return;
        }
        dprintf(client->fd, "250 Requested file action okay, completed.\n");
    } else {
        dprintf(client->fd, "530 Not logged in.\n");
    }
}

void exec_pwd(client_t *client, char **params)
{
    if (client->login == LOGIN_CNCT) {
        client->path = getcwd(NULL, 0);
        dprintf(client->fd, "257 \"%s\" is current directory.\n",
            client->path);
    } else {
        dprintf(client->fd, "530 Not logged in.\n");
    }
}

void exec_pasv(client_t *client, char **params)
{
    if (client->login == LOGIN_CNCT) {
        dprintf(client->fd, "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\n");
    } else {
        dprintf(client->fd, "530 Not logged in.\n");
    }
}

void exec_help(client_t *client, char **params)
{
    int fd = client->fd;

    dprintf(fd, "214 Help message.\n");
    dprintf(fd, "USER {username} : Specifiy user for authentication.\n");
    dprintf(fd, "PASS {password} : Specifiy password for authentication.\n");
    dprintf(fd, "CWD {pathname} : Change working directory.\n");
    dprintf(fd, "CDUP : Change working directory to parent directory.\n");
    dprintf(fd, "QUIT : Disconnection.\n");
    dprintf(fd, "DELE {pathname} : Delete file on the server.\n");
    dprintf(fd, "PWD : Print working directory.\n");
    dprintf(fd, "PASV : Enable \"passive\" mode for data transfer.\n");
    dprintf(fd,
        "PORT {host-port} : Enable \"active\" mode for data transfer.\n");
    dprintf(fd, "HELP : List available commands.\n");
    dprintf(fd, "NOOP : Do nothing.\n");
    dprintf(fd, "RETR {pathname} : Download file from server to client.\n");
    dprintf(fd, "STOR {pathname} : Upload file from client to server.\n");
    dprintf(fd,
        "LIST {pathname} : List files in the current working directory.\n");
}
