/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** find_channel
*/

#include "items/channel.h"
#include "items/team.h"
#include "server.h"

#include <string.h>

channel_t *server_find_channel_inner(team_t const *team, uuid_t id)
{
    channel_t *c = LIST_FIRST(&team->channels);

    while (c) {
        if (uuid_compare(id, c->header.id) == 0)
            return c;
        c = LIST_NEXT(c, channels);
    }
    return NULL;
}

channel_t *server_find_channel(server_t const *server, uuid_t id)
{
    team_t *t = LIST_FIRST(&server->teams);
    channel_t *result;

    while (t) {
        result = server_find_channel_inner(t, id);
        if (result)
            return result;
        t = LIST_NEXT(t, teams);
    }
    return NULL;
}

static channel_t *server_find_channel_by_name_inner(
    team_t const *team, char const *name)
{
    channel_t *c = LIST_FIRST(&team->channels);

    while (c) {
        if (strcmp(name, c->name) == 0)
            return c;
        c = LIST_NEXT(c, channels);
    }
    return NULL;
}

channel_t *server_find_channel_by_name(
    server_t const *server, char const *name)
{
    team_t *t = LIST_FIRST(&server->teams);
    channel_t *result;

    while (t) {
        result = server_find_channel_by_name_inner(t, name);
        if (result)
            return result;
        t = LIST_NEXT(t, teams);
    }
    return NULL;
}
