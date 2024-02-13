/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Remove an user session
*/

#include "items/user.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"
#include "packet_reply.h"

#include <stdbool.h>
#include <stdlib.h>

static void notify_logout(peer_t *peer)
{
    server_t *server = peer->server;
    user_t *user = peer->user;

    server_event_user_logged_out(user->id_str);
    for (peer_t *p = LIST_FIRST(&server->peers); p; p = LIST_NEXT(p, peers)) {
        if (p->user)
            reply_logout(p, user->id, user->name);
    }
    if (LIST_EMPTY(&user->sessions))
        peer_log(peer, "Logged out (all sessions closed)");
    else
        peer_log(peer, "Session closed");
}

void peer_unset_user(peer_t *peer, bool print_logout_message)
{
    user_t *user = peer->user;
    user_session_t *session;

    if (user == NULL)
        return;
    session = LIST_FIRST(&user->sessions);
    while (session && session->peer != peer)
        session = LIST_NEXT(session, sessions);
    if (session)
        LIST_REMOVE(session, sessions);
    free(session);
    if (print_logout_message)
        notify_logout(peer);
    peer->user = NULL;
}
