/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Writers to server-to-client packets
*/

#pragma once

#include "protocol.h"

struct peer;
struct team;
struct channel;
struct thread;
struct message;
struct comment;

/// Generic response packet
///
/// @param peer The peer to send the response to.
/// @param code The response code.
/// @param description The message to write, a nul-terminated string that must
/// not exceed @c MAX_BODY_LENGTH in size.
void reply_generic(
    struct peer *peer, reply_code_t code, char const *description);

/// Writes a generic packet and removes @b bytes_to_drop bytes the peer's
/// input buffer
///
/// @param peer The peer to send the response to.
/// @param code The response code.
/// @param description The message to write, a nul-terminated string that must
/// not exceed @c MAX_BODY_LENGTH in size.
/// @param bytes_to_drop The number of bytes to pop() from the peer's buffer,
/// may exceed the actual buffer's size.
void reply_error(struct peer *peer, reply_code_t code,
    char const *description, size_t bytes_to_drop);

/// Writes a login or logout response packet to the peer.
void reply_login_logout(
    struct peer *peer, uuid_t id, char const *name, s2c_packet_id_t type);

/// Writes a login response packet to the peer.
void reply_login(struct peer *peer, uuid_t id, char const *name);

/// Writes a generic logout packet to the peer.
void reply_logout(struct peer *peer, uuid_t id, char const *name);

/// Writes the list of all users to the peer.
void reply_user_list(struct peer *peer);

/// Writes the list of all direct messages between the peer and the recipient.
void reply_message_list(struct peer *peer, uuid_t recipient);

/// Writes the list of all teams on this domain.
///
/// @param filter_subscribed Set to true to only include the teams the user is
/// subscribed to.
void reply_team_list(struct peer *peer, bool filter_subscribed);

/// Writes the list of all channels on a team.
void reply_channel_list(struct peer *peer, uuid_t team_id);

/// Writes the list of all threads on a channel.
void reply_thread_list(peer_t *peer, uuid_t team_id, uuid_t channel_id);

/// Writes the list of all comments on a thread.
void reply_comment_list(
    peer_t *peer, uuid_t team_id, uuid_t channel_id, uuid_t thread_id);

/// Writes a team creation notification.
void reply_team_created(struct peer *peer, struct team *team);

/// Writes a private message notification.
void reply_message(
    peer_t *peer_dst, struct message *message, my_cbuffer_t *out);

/// Writes a channel creation notification.
void reply_channel_created(peer_t *peer, struct channel *channel);

/// Writes a thread creation notification.
void reply_thread_created(peer_t *peer, struct thread *thread);

/// Writes a thread reply creation notification.
void reply_comment_created(peer_t *peer, struct comment *comment);

/// Writes the information of a user on this domain.
void reply_user_info(peer_t *peer, uuid_t user_id);

/// Writes subscribed users of a specific team.
void reply_subscribed(peer_t *peer, uuid_t team_id);

/// Send unsubscribed packet.
void reply_unsubscribed(peer_t *peer, uuid_t team_id);

/// Writes an unknown item (team/channel/thread/user) notification.
void reply_unknown_item(peer_t *peer, uuid_t id, reply_code_t reply_code);

/// Writes all users of a specific team.
void reply_team_users_list(peer_t *peer, uuid_t id, size_t length);

/// Writes info of a specific team.
void reply_team_info(peer_t *peer, uuid_t id, size_t length);

void reply_context_update(peer_t *peer);
