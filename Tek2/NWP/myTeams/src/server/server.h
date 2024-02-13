/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** The main server header file
*/

#pragma once

#include "items/message.h"
#include "items/team.h"
#include "items/user.h"
#include "peer.h"
#include "hash_map.h"

#include <stdbool.h>
#include <stdint.h>

#define MAX_CONNECTIONS 4096

struct channel;
struct thread;
struct user;

/// The MyTeams server.
typedef struct server {
    int socket;
    peer_list_t peers;
    fd_set poll_fds_in;
    fd_set poll_fds_out;
    /// Teams list.
    team_list_t teams;
    /// List of all users, connected or not.
    user_list_t users;
    /// Direct messages map:
    /// key = uuid_pair_t
    /// value = message_list_t
    my_hash_map_t messages;
} server_t;

/// @param[out] server The server to initialize.
/// @param port The port to listen.
///
/// @retval true If server was successfully initialized.
/// @retval false On error.
bool server_init(server_t *server, uint16_t port);

/// Frees all resources allocated by the server.
void server_destroy(server_t *server);

/// Destroys the teams of a server.
void server_destroy_teams(server_t *server);

/// Runs the server until the SIGINT signal is received.
void server_start(server_t *server);

void server_cycle(server_t *server);

bool server_poll(server_t *server);

bool server_connection_ready(server_t const *server);

bool server_peer_in_ready(
    server_t const *restrict server, peer_t const *peer);

bool server_peer_out_ready(
    server_t const *restrict server, peer_t const *peer);

/// Opens a socket that listens on the given port.
///
/// @param[out] sockfd Where the file descriptor of the opened socket is
/// written.
/// @param port The port to listen.
///
/// @retval true If the socket was successfully opened.
/// @retval false On error.
bool socket_listen(int *sockfd, uint16_t port);

/// Closes the given socket.
///
/// @retval true If the socket was successfully closed.
/// @retval false On error.
bool socket_close(int sockfd);

void server_init_users_map(my_hash_map_t *users);
void server_init_messages_map(my_hash_map_t *users);

/// Deduces the type of context from a UUID.
context_type_t server_get_context_type(
    server_t const *server, uuid_t context);

/// @returns The team identified by @b id, or @c NULL if not found.
struct team *server_find_team(server_t const *server, uuid_t id);

/// @returns The team identified by @b name, or @c NULL if not found.
struct team *server_find_team_by_name(
    server_t const *server, char const *name);

/// @returns The channel identified by @b id, or @c NULL if not found.
struct channel *server_find_channel(server_t const *server, uuid_t id);

/// @returns The channel identified by @b name, or @c NULL if not found.
struct channel *server_find_channel_by_name(
    server_t const *server, char const *name);

/// @returns The channel identified by @b id, or @c NULL if not found.
channel_t *server_find_channel_inner(team_t const *team, uuid_t id);

/// @returns The thread identified by @b id, or @c NULL if not found.
struct thread *server_find_thread(server_t const *server, uuid_t id);

/// @returns The thread identified by @b title, or @c NULL if not found.
struct thread *server_find_thread_by_title(
    server_t const *server, char const *title);

/// @returns The thread identified by @b id, or @c NULL if not found.
struct thread *server_find_thread_inner(team_t const *team, uuid_t id);

/// @returns The thread identified by @b id, or @c NULL if not found.
struct thread *server_find_thread_inner2(channel_t const *channel, uuid_t id);

/// @returns The peer identified by @b id, or @c NULL if not found.
struct peer *server_find_peer(server_t *server, uuid_t id);

/// @returns The user with the given name, or @c NULL if not found.
struct user *server_find_user_by_name(server_t *server, char const *name);

/// @returns The user with the given id, or @c NULL if not found.
struct user *server_find_user(server_t *server, uuid_t id);

/// Returns the list of messages between the users @b a and @b b.
///
/// @returns The message list, or @c NULL if it does not exist.
message_list_t *server_find_messages_list(
    server_t *server, uuid_t a, uuid_t b);
