/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** server
*/

#include "ftp.h"

ftp_t *init_sock(ftp_t *ftp)
{
    ftp->sock_size = sizeof(ftp->sock);
    ftp->sock.sin_family = AF_INET;
    ftp->sock.sin_port = htons(ftp->port);
    ftp->sock.sin_addr.s_addr = INADDR_ANY;
    return (ftp);
}

ftp_t *init_server(char *port, char *path)
{
    ftp_t *ftp = malloc(sizeof(ftp_t));

    if (chdir(path) < 0) {
        fprintf(stderr, "Error: Invalid path : '%s'\n", path);
        return NULL;
    }
    if ((ftp->server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 1) {
        fprintf(stderr, "Err: Socket");
        return NULL;
    }
    ftp->path = path;
    if (!check_port(port)) {
        fprintf(stderr, "Err: Invalid port\n");
        return NULL;
    }
    ftp->port = atoi(port);
    ftp = init_sock(ftp);
    return (ftp);
}

bool start_server(ftp_t* server)
{
    if (bind(server->server_fd, (struct sockaddr *)&server->sock,
        sizeof(server->sock)) < 0) {
        shutdown(server->server_fd, SHUT_RDWR);
        close(server->server_fd);
        fprintf(stderr, "Err: Bind\n");
        return false;
    }
    if (listen(server->server_fd, CLIENT_MAX_NB) < 0){
        close(server->server_fd);
        fprintf(stderr, "Err: Listen\n");
        return false;
    }
    return true;
}
