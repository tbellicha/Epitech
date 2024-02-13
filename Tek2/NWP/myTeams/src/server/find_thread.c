/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** find_thread
*/

#include "items/channel.h"
#include "items/team.h"
#include "items/thread.h"
#include "server.h"

thread_t *server_find_thread_inner2(channel_t const *channel, uuid_t id)
{
    thread_t *thread = LIST_FIRST(&channel->threads);

    while (thread) {
        if (uuid_compare(id, thread->header.id) == 0)
            return thread;
        thread = LIST_NEXT(thread, threads);
    }
    return NULL;
}

thread_t *server_find_thread_inner(team_t const *team, uuid_t id)
{
    channel_t *channel = LIST_FIRST(&team->channels);
    thread_t *result;

    while (channel) {
        result = server_find_thread_inner2(channel, id);
        if (result)
            return result;
        channel = LIST_NEXT(channel, channels);
    }
    return NULL;
}

thread_t *server_find_thread(server_t const *server, uuid_t id)
{
    team_t *team = LIST_FIRST(&server->teams);
    thread_t *result;

    while (team) {
        result = server_find_thread_inner(team, id);
        if (result)
            return result;
        team = LIST_NEXT(team, teams);
    }
    return NULL;
}
