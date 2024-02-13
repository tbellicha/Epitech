/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Set the user of a peer
*/

#include "items/user.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool peer_create_user(peer_t *peer, char const *name, user_t **user)
{
    *user = calloc(sizeof(**user), 1);

    if (*user == NULL)
        return false;
    peer_unset_user(peer, false);
    uuid_generate((*user)->id);
    uuid_unparse((*user)->id, (*user)->id_str);
    LIST_INIT(&(*user)->sessions);
    (*user)->timestamp = time(NULL);
    strncpy((*user)->name, name, MAX_NAME_LENGTH);
    server_event_user_created((*user)->id_str, (*user)->name);
    peer_log(peer, "Created user '%s'", (*user)->name);
    LIST_INSERT_HEAD(&peer->server->users, *user, users);
    return true;
}

static bool peer_add_user_session(peer_t *peer, user_t *user)
{
    user_session_t *session = calloc(sizeof(*session), 1);

    if (session == NULL)
        return false;
    session->peer = peer;
    LIST_INSERT_HEAD(&user->sessions, session, sessions);
    peer->user = user;
    return true;
}

bool peer_set_user(peer_t *peer, char const *name)
{
    user_t *user;

    if (peer->user && strcmp(peer->user->name, name) == 0)
        return true;
    user = server_find_user_by_name(peer->server, name);
    if (!user && !peer_create_user(peer, name, &user))
        return false;
    return peer_add_user_session(peer, user);
}
