/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** log
*/

#include "items/user.h"
#include "peer.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static void peer_log_inner(peer_t *peer, char const *format, va_list *args)
{
    char const *addr_str = inet_ntoa(peer->address.sin_addr);
    uint16_t port = ntohs(peer->address.sin_port);
    bool has_color = !!isatty(STDIN_FILENO);
    char const *bold_blue = has_color ? "\033[1;34m" : "";
    char const *bold_yellow = has_color ? "\033[1;33m" : "";
    char const *reset = has_color ? "\033[0m" : "";

    if (peer->user)
        printf("%s%s:%d %s(%.8s)%s - ", bold_blue, addr_str, port,
            bold_yellow, peer->user->id_str, reset);
    else
        printf("%s%s:%d%s - ", bold_blue, addr_str, port, reset);
    vprintf(format, *args);
    putc('\n', stdout);
    fflush(stdout);
}

void peer_log(peer_t *peer, char const *format, ...)
{
    va_list args;

    if (peer->fd == -1)
        return;
    va_start(args, format);
    peer_log_inner(peer, format, &args);
    va_end(args);
}
