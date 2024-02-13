/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Handlers of client packets
*/

#pragma once

#include "peer.h"
#include "protocol.h"

#include <stddef.h>

/// Return code for the packet handler functions.
typedef enum packet_result {
    /// Returned when the packet handler sent a reply to the peer.
    PRESULT_OK = 0,
    /// Returned when the packet handler needs more data to proceed.
    PRESULT_NOT_ENOUGH_DATA = 1,
    /// Returned when the client sent too much data.
    PRESULT_FULL_BUFFER = 2,
    /// When something really wrong happened.
    PRESULT_INTERNAL_ERROR = 3,
} packet_result_t;

/// Type of functions to call for each packet type.
typedef packet_result_t (*packet_handler_t)(peer_t *, size_t length);

/// Handles the next packet in the peers input buffer.
packet_result_t handle_packet(peer_t *peer);

/// Packets handlers from 0 to C2S_PACKET_COUNT.
///
/// A @c NULL function means that the @ref handle_unknown_packet function
/// needs to be called.
extern const packet_handler_t PACKET_HANDLERS[C2S_PACKET_COUNT];

/// Function to call when packet id is not known.
packet_result_t handle_unknown_packet(struct peer *peer, size_t length);

packet_result_t handle_login_packet(peer_t *peer, size_t length);
packet_result_t handle_logout_packet(peer_t *peer, size_t length);
packet_result_t handle_get_users_packet(peer_t *peer, size_t length);
packet_result_t handle_get_user_info_packet(peer_t *peer, size_t length);
packet_result_t handle_message_packet(peer_t *peer, size_t length);
packet_result_t handle_get_messages_packet(peer_t *peer, size_t length);
packet_result_t handle_get_team_users_packet(peer_t *peer, size_t length);
packet_result_t handle_get_team_info_packet(peer_t *peer, size_t length);
packet_result_t handle_subscribe_team_packet(peer_t *peer, size_t length);
packet_result_t handle_get_subscribed_teams_packet(
    peer_t *peer, size_t length);
packet_result_t handle_unsubscribe_team_packet(peer_t *peer, size_t length);
packet_result_t handle_create_item_packet(peer_t *peer, size_t length);
packet_result_t handle_get_teams_packet(peer_t *peer, size_t length);
packet_result_t handle_get_threads_packet(peer_t *peer, size_t length);
packet_result_t handle_get_comments_packet(peer_t *peer, size_t length);
packet_result_t handle_get_channels_packet(peer_t *peer, size_t length);
packet_result_t handle_set_context_packet(peer_t *peer, size_t length);

#if MAX_BODY_LENGTH > MAX_DESCRIPTION_LENGTH
    /// Set to @ref MAX_BODY_LENGTH or @c MAX_DESCRIPTION_LENGTH, depending on
    /// which is bigger.
    #define MAX_ITEM_BODY_LENGTH MAX_BODY_LENGTH
#else
    /// Set to @ref MAX_BODY_LENGTH or @c MAX_DESCRIPTION_LENGTH, depending on
    /// which is bigger.
    #define MAX_ITEM_BODY_LENGTH MAX_DESCRIPTION_LENGTH
#endif

/// Deserialized version of the C2S_CREATE_ITEM packet.
///
/// This is necessary to malloc() the space needed for name and body.
typedef struct create_item_packet {
    uuid_t context_id;
    uint32_t name_length;
    char name[MAX_NAME_LENGTH + 1];
    uint32_t body_length;
    char body[MAX_ITEM_BODY_LENGTH + 1];
} create_item_packet_t;
