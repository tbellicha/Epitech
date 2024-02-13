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

#include <string.h>

static thread_t *server_find_thread_by_title_inner2(
    channel_t const *channel, char const *title)
{
    thread_t *thread = LIST_FIRST(&channel->threads);

    while (thread) {
        if (strcmp(title, thread->title) == 0)
            return thread;
        thread = LIST_NEXT(thread, threads);
    }
    return NULL;
}

thread_t *server_find_thread_by_title_inner(
    team_t const *team, char const *title)
{
    channel_t *channel = LIST_FIRST(&team->channels);
    thread_t *result;

    while (channel) {
        result = server_find_thread_by_title_inner2(channel, title);
        if (result)
            return result;
        channel = LIST_NEXT(channel, channels);
    }
    return NULL;
}

thread_t *server_find_thread_by_title(
    server_t const *server, char const *title)
{
    team_t *team = LIST_FIRST(&server->teams);
    thread_t *result;

    while (team) {
        result = server_find_thread_by_title_inner(team, title);
        if (result)
            return result;
        team = LIST_NEXT(team, teams);
    }
    return NULL;
}
