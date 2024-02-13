/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Handlers of server packets
*/

#pragma once

#include "client.h"
#include "protocol.h"

/// Return code for the packet handler functions.
typedef enum server_packet_result {
    /// Returned when the packet handler has been fully read.
    PRESULT_OK = 0,
    /// Returned when the packet handler needs more data to proceed.
    PRESULT_NOT_ENOUGH_DATA = 1,
    /// Returned when the server sent too much data.
    PRESULT_FULL_BUFFER = 2,
    /// When something really wrong happened.
    PRESULT_INTERNAL_ERROR = 3,
} server_packet_result_t;

typedef server_packet_result_t (*server_packet_handler_t)(
    client_t *, uint32_t length);

server_packet_result_t handle_packet_server(client_t *client);

/// Packets handlers from 0 to S2C_PACKET_COUNT.
///
/// A @c NULL function means that the @ref handle_unknown_packet function
/// needs to be called.
extern const server_packet_handler_t S2C_PACKET_HANDLERS[S2C_PACKET_COUNT];

server_packet_result_t s2c_handle_generic_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_login_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_logout_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_message_list_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_message_created_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_team_list_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_team_created_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_channel_created_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_channel_list_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_user_list_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_thread_created_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_user_info_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_subscribed_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_unsubscribed_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_unknown_item_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_team_info_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_comment_created_packet(
    client_t *client, uint32_t len);

server_packet_result_t s2c_handle_context_update_packet(
    client_t *client, uint32_t len);
