/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** destroy_teams
*/

#include "items/channel.h"
#include "items/comment.h"
#include "items/team.h"
#include "items/thread.h"
#include "server.h"

#include <stdlib.h>

static void server_destroy_thread(thread_t *thread)
{
    comment_t *comment = LIST_FIRST(&thread->comments);
    comment_t *next;

    while (comment) {
        next = LIST_NEXT(comment, comments);
        comment->thread = NULL;
        free(comment);
        comment = next;
    }
    thread->channel = NULL;
    free(thread);
}

static void server_destroy_channel(channel_t *channel)
{
    thread_t *thread = LIST_FIRST(&channel->threads);
    thread_t *next;

    while (thread) {
        next = LIST_NEXT(thread, threads);
        server_destroy_thread(thread);
        thread = next;
    }
    channel->team = NULL;
    free(channel);
}

static void server_destroy_team(team_t *team)
{
    channel_t *channel = LIST_FIRST(&team->channels);
    channel_t *next_channel;
    team_subscriber_t *sub = LIST_FIRST(&team->subscribers);
    team_subscriber_t *next_sub;

    while (channel) {
        next_channel = LIST_NEXT(channel, channels);
        server_destroy_channel(channel);
        channel = next_channel;
    }
    while (sub) {
        next_sub = LIST_NEXT(sub, subscribers);
        free(sub);
        sub = next_sub;
    }
    free(team);
}

void server_destroy_teams(server_t *server)
{
    team_t *team;
    team_t *next;

    team = LIST_FIRST(&server->teams);
    while (team) {
        next = LIST_NEXT(team, teams);
        server_destroy_team(team);
        team = next;
    }
}
