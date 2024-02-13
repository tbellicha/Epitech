/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Server peers
*/

#pragma once

#include "cbuffer.h"
#include "protocol.h"

#include <netinet/in.h>
#include <stdbool.h>
#include <sys/queue.h>
#include <uuid/uuid.h>

/// 1 Megabibyte.
#define PEER_BUFFER_SIZE (1 << 20)

struct server;
struct item;
struct user;
struct team;

/// Represents a single connection.
typedef struct peer {
    struct server *server;
    /// The coresponding user, set to @b NULL if not logged in.
    struct user *user;
    int fd;
    struct sockaddr_in address;
    my_cbuffer_t in_buf;
    my_cbuffer_t out_buf;
    uuid_t context;
    context_type_t context_type;
    LIST_ENTRY(peer) peers;
    /// The memory used by the circular buffer.
    char raw_in_buf[PEER_BUFFER_SIZE];
    char raw_out_buf[PEER_BUFFER_SIZE];
    /// Temporary buffer for received data.
    char tmp_buffer[PEER_BUFFER_SIZE];
} peer_t;

LIST_HEAD(peer_list, peer);

/// A doubly linked list of peers.
typedef struct peer_list peer_list_t;

/// Allocates, then connect to a peer.
///
/// @param fd The peer's socket file descriptor.
/// @param address The address of the peer.
///
/// @return The peer data, allocated.
peer_t *peer_create(int fd, struct sockaddr_in const *address);

/// Frees an allocated peer's data.
///
/// @param peer The peer to destroy, may be @c NULL.
/// @param print_logout_message Pass @c true to enable the logout message.
void peer_destroy(peer_t *peer, bool print_logout_message);

/// @returns The peer's remaining buffer capacity.
static inline size_t peer_buffer_remaining(peer_t const *peer)
{
    return peer->in_buf.cap - peer->in_buf.len;
}

/// Reads input from a peer's socket.
///
/// @param[in,out] peer The address to a peer, set to NULL after the call if
/// the peer is disconnected.
void peer_read_input(peer_t **peer);

/// Writes output to a peer's socket.
///
/// @param[in,out] peer The address to a peer, set to NULL after the call if
/// the peer is disconnected.
void peer_write_output(peer_t **peer);

/// Checks if the peer is connected, and if not writes an error packet.
///
/// @param peer The peer.
/// @param packet_length The number of bytes to remove from the packet.
///
/// @returns Whether the user is logged in.
bool peer_check_logged_in(peer_t *peer, size_t packet_length);

#ifdef __GNUC__
    /// Enables compile-time checking of format parameters.
    #define PRINTF_LIKE(f) __attribute__((format(printf, f, f + 1)))
#else
    /// Enables compile-time checking of format parameters.
    #define PRINTF_LIKE(f)
#endif

/// Prints a formatted message, prefixed the peer's IP and port.
///
/// @param peer The peer.
/// @param format A printf-like format.
/// @param ... The format arguments.
void peer_log(peer_t *peer, char const *format, ...) PRINTF_LIKE(2);

/// Initializes the header of an item using the peer's id as the creator and
/// set the creation timestamp to now.
void peer_init_item_header(peer_t *peer, struct item *header);

typedef bool (*peer_item_creator_t)(
    peer_t *, uuid_t, char const *, char const *);

/// Holds the corresponding item creation function for each context.
extern peer_item_creator_t PEER_ITEM_CREATORS[];

/// @retval true If the team was created, or it was already created.
/// @retval false On internal error.
bool peer_create_team(
    peer_t *peer, uuid_t unused, char const *name, char const *description);

/// @retval true If the team was created, or it was already created.
/// @retval false On internal error.
bool peer_create_channel(
    peer_t *peer, uuid_t team_id, char const *name, char const *description);

/// @retval true If the team was created, or it was already created.
/// @retval false On internal error.
bool peer_create_thread(
    peer_t *peer, uuid_t channel_id, char const *title, char const *body);

/// @retval true If the team was created, or it was already created.
/// @retval false On internal error.
bool peer_create_comment(
    peer_t *peer, uuid_t thread_id, char const *unused, char const *body);

/// Associates a peer with an user, if an user identified by @b name does not
/// exist, a new user is created.
bool peer_set_user(peer_t *peer, char const *name);

/// Diassociates a peer with its user.
///
/// @param print_logout_message Whether to print to session closed message.
void peer_unset_user(peer_t *peer, bool print_logout_message);

/// @returns Whether the user attached to this peer is subscribed to the given
/// team.
bool peer_is_subscribed(peer_t *peer, struct team *team);

/// @returns Whether an item identified by @c id exists, context sensitive.
bool peer_item_exists(peer_t *peer, uuid_t id);

/// @returns Whether an item identified by @c name exists, context sensitive.
bool peer_item_exists_by_name(peer_t *peer, char const *name);
