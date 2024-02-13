/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** set_context
*/

#include "peer.h"
#include "server.h"
#include "packet_handlers.h"
#include "packet_reply.h"

#include <stdbool.h>
#include <string.h>

static const char *CONTEXT_NAMES[CONTEXT_COUNT] = {
    [CONTEXT_NONE] = "none",
    [CONTEXT_TEAM] = "team",
    [CONTEXT_CHANNEL] = "channel",
    [CONTEXT_THREAD] = "thread",
};

static bool set_context_error(peer_t *peer)
{
    switch (peer->context_type) {
        case CONTEXT_NONE:
            reply_error(
                peer, REPLY_UNKNOWN_TEAM, "cannot use unknown team", 0);
            break;
        case CONTEXT_TEAM:
            reply_error(
                peer, REPLY_UNKNOWN_CHANNEL, "cannot use unknown channel", 0);
            break;
        case CONTEXT_CHANNEL:
            reply_error(
                peer, REPLY_UNKNOWN_THREAD, "cannot use unknown thread", 0);
            break;
        default:
        case CONTEXT_THREAD:
            reply_error(
                peer, REPLY_UNKNOWN_THREAD, "cannot use unknown thread", 0);
            break;
    }
    return false;
}

static bool pop_context_path(peer_t *peer, size_t *count, uuid_t *path)
{
    if (!peer_item_exists(peer, *path))
        return set_context_error(peer);
    ++peer->context_type;
    uuid_copy(peer->context, *path);
    memmove(path, path + 1, sizeof(uuid_t));
    --(*count);
    return true;
}

static bool advance_context_path(peer_t *peer, size_t count, uuid_t *path)
{
    context_type_t old_type = peer->context_type;
    char id_str[37] = {0};

    if (count == 3)
        peer->context_type = CONTEXT_NONE;
    while (count > 0) {
        if (!pop_context_path(peer, &count, path)) {
            peer->context_type = old_type;
            return false;
        }
    }
    uuid_unparse(peer->context, id_str);
    peer_log(peer, "Set context to %s (%.8s)",
        CONTEXT_NAMES[peer->context_type], id_str);
    reply_context_update(peer);
    return true;
}

packet_result_t handle_set_context_packet(peer_t *peer, size_t length)
{
    size_t count;
    uuid_t path[3];

    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    if (length != 0 && length != 16 && length != 24 && length != 32) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "set_context requires between 0 and 3 UUIDs", length);
        return PRESULT_OK;
    }
    count = length / sizeof(uuid_t);
    for (size_t i = 0; i < count; ++i)
        my_cbuffer_pop_front(&peer->in_buf, path[i], sizeof(uuid_t));
    advance_context_path(peer, count, path);
    return PRESULT_OK;
}
