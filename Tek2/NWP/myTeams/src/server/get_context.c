/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** server_get_context
*/

#include "server.h"

#include <stdbool.h>
#include <sys/queue.h>

static context_type_t channel_get_context_type(
    channel_t const *channel, uuid_t context)
{
    thread_t *t = LIST_FIRST(&channel->threads);

    while (t) {
        if (uuid_compare(t->header.id, context) == 0)
            return CONTEXT_THREAD;
        t = LIST_NEXT(t, threads);
    }
    return CONTEXT_NONE;
}

static context_type_t team_get_context_type(
    team_t const *team, uuid_t context)
{
    context_type_t type;
    channel_t *c = LIST_FIRST(&team->channels);

    while (c) {
        if (uuid_compare(c->header.id, context) == 0)
            return CONTEXT_CHANNEL;
        type = channel_get_context_type(c, context);
        if (type != CONTEXT_NONE)
            return type;
        c = LIST_NEXT(c, channels);
    }
    return CONTEXT_NONE;
}

// Recursively looking for the id, not very efficient, subject to change.
context_type_t server_get_context_type(server_t const *server, uuid_t context)
{
    context_type_t type;
    team_t *t = LIST_FIRST(&server->teams);

    while (t) {
        if (uuid_compare(t->header.id, context) == 0)
            return CONTEXT_TEAM;
        type = team_get_context_type(t, context);
        if (type != CONTEXT_NONE)
            return type;
        t = LIST_NEXT(t, teams);
    }
    return CONTEXT_NONE;
}
