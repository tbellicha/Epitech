/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** create_comment
*/

#include "items/channel.h"
#include "items/comment.h"
#include "items/team.h"
#include "items/thread.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"
#include "packet_reply.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void init_comment_header(comment_t *comment, peer_t *peer)
{
    uuid_copy(comment->header.creator, peer->user->id);
    uuid_generate(comment->header.id);
    uuid_unparse(comment->header.creator, comment->header.creator_str);
    uuid_unparse(comment->header.id, comment->header.id_str);
    comment->header.timestamp = time(NULL);
}

static void notify_comment_creation(peer_t *peer, comment_t *comment)
{
    thread_t const *thread = comment->thread;
    server_t *server = peer->server;

    init_comment_header(comment, peer);
    server_event_reply_created(
        thread->header.id_str, comment->header.creator_str, comment->body);
    peer_log(peer, "Reply posted to '%s' (%.8s): '%s' (%s)", thread->title,
        thread->header.id_str, comment->body, comment->header.id_str);
    for (peer_t *p = LIST_FIRST(&server->peers); p; p = LIST_NEXT(p, peers)) {
        if (peer_is_subscribed(p, comment->thread->channel->team))
            reply_comment_created(p, comment);
    }
}

static bool check_subscribed(peer_t *peer, team_t *team, comment_t *comment)
{
    if (!peer_is_subscribed(peer, team)) {
        reply_error(peer, REPLY_NOT_SUBSCRIBED,
            "you are not subscribed to this team", 0);
        free(comment);
        return false;
    }
    return true;
}

bool peer_create_comment(
    peer_t *peer, uuid_t thread_id, char const *unused, char const *body)
{
    thread_t *thread = server_find_thread(peer->server, thread_id);
    comment_t *comment = calloc(sizeof(*comment), 1);

    (void)unused;
    if (!thread || !comment) {
        free(comment);
        return false;
    }
    if (!check_subscribed(peer, thread->channel->team, comment))
        return true;
    peer_init_item_header(peer, &thread->header);
    comment->thread = thread;
    strncpy(comment->body, body, MAX_BODY_LENGTH);
    LIST_INSERT_HEAD(&thread->comments, comment, comments);
    notify_comment_creation(peer, comment);
    return true;
}
