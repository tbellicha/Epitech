/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** client_struct
*/

#pragma once

#include "cbuffer.h"
#include "protocol.h"

#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/select.h>
#include <uuid/uuid.h>

/// 1 Megabibyte.
#define CLIENT_BUFFER_SIZE (1 << 20)

/// Client structure.
typedef struct {
    /// Whether the client is running in an interactive terminal.
    bool tty;
    /// Socket file descriptor of the server.
    int sock_fd;
    /// Current context uuid.
    context_type_t context_type;
    /// Size of socket.
    size_t sock_size;
    /// Client socket address.
    struct sockaddr_in sockaddr;
    /// Context structure
    uuid_t context;
    /// The UUID of the client.
    uuid_t uuid;
    /// Name of the client.
    char name[MAX_NAME_LENGTH + 1];
    /// Circular buffer for inbound data.
    my_cbuffer_t in_buf;
    /// Circular buffer for outbound data.
    my_cbuffer_t out_buf;
    /// Input file descriptors.
    fd_set fds_in;
    /// Output file descriptors.
    fd_set fds_out;
    /// The memory used by the circular buffer.
    char raw_in_buf[CLIENT_BUFFER_SIZE];
    char raw_out_buf[CLIENT_BUFFER_SIZE];
    char tmp_buf[CLIENT_BUFFER_SIZE];
} client_t;
