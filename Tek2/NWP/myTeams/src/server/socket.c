/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** Opens a socket
*/

#include "server.h"

#include <errno.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

bool socket_listen(int *sockfd, uint16_t port)
{
    struct sockaddr_in address;

    *sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*sockfd == -1)
        return false;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(*sockfd, (struct sockaddr *)&address, sizeof(address)) == -1
        || listen(*sockfd, MAX_CONNECTIONS) == -1)
        return socket_close(*sockfd);
    return true;
}

bool socket_close(int sockfd)
{
    int old_errno;

    if (sockfd != -1) {
        old_errno = errno;
        close(sockfd);
        errno = old_errno;
    }
    return false;
}
