/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Receive login client packet
*/

#include "items/user.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"
#include "packet_handlers.h"
#include "packet_reply.h"

static void notify_login(peer_t *peer)
{
    server_t *server = peer->server;
    user_t *user = peer->user;

    server_event_user_logged_in(user->id_str);
    peer_log(peer, "User '%s' logged in", user->name);
    for (peer_t *p = LIST_FIRST(&server->peers); p; p = LIST_NEXT(p, peers)) {
        if (p->user)
            reply_login(p, user->id, user->name);
    }
}

packet_result_t handle_login_packet(peer_t *peer, size_t length)
{
    char name[MAX_NAME_LENGTH + 1] = {0};

    if (length == 0 || length > MAX_NAME_LENGTH) {
        reply_error(
            peer, REPLY_INVALID_LENGTH, "invalid name length", length);
        return PRESULT_OK;
    }
    my_cbuffer_pop_front(&peer->in_buf, name, length);
    if (!peer_set_user(peer, name))
        return PRESULT_INTERNAL_ERROR;
    notify_login(peer);
    return PRESULT_OK;
}
