/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** create_thread
*/

#include "items/channel.h"
#include "items/team.h"
#include "items/thread.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"
#include "packet_reply.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void notify_thread_creation(peer_t *peer, thread_t *thread)
{
    channel_t const *channel = thread->channel;
    team_t const *team = channel->team;
    server_t *server = peer->server;

    server_event_thread_created(channel->header.id_str, thread->header.id_str,
        thread->header.creator_str, thread->title, thread->body);
    peer_log(peer,
        "Created thread '%s' (%.8s) in channel '%s' (%.8s) of '%s' (%.8s), "
        "with description '%s'",
        thread->title, thread->header.id_str, channel->name,
        channel->header.id_str, team->name, team->header.id_str,
        thread->body);
    for (peer_t *p = LIST_FIRST(&server->peers); p; p = LIST_NEXT(p, peers)) {
        if (peer_is_subscribed(p, thread->channel->team))
            reply_thread_created(p, thread);
    }
}

static bool check_subscribed(peer_t *peer, team_t *team, thread_t *thread)
{
    if (!peer_is_subscribed(peer, team)) {
        reply_error(peer, REPLY_NOT_SUBSCRIBED,
            "you are not subscribed to this team", 0);
        free(thread);
        return false;
    }
    return true;
}

bool peer_create_thread(
    peer_t *peer, uuid_t channel_id, char const *title, char const *body)
{
    channel_t *channel = server_find_channel(peer->server, channel_id);
    thread_t *thread = calloc(sizeof(*thread), 1);

    if (!channel || !thread) {
        free(thread);
        return false;
    }
    if (!check_subscribed(peer, channel->team, thread))
        return true;
    peer_init_item_header(peer, &thread->header);
    thread->channel = channel;
    LIST_INIT(&thread->comments);
    strncpy(thread->title, title, MAX_NAME_LENGTH);
    strncpy(thread->body, body, MAX_BODY_LENGTH);
    LIST_INSERT_HEAD(&channel->threads, thread, threads);
    notify_thread_creation(peer, thread);
    return true;
}
