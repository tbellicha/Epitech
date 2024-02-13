/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_handlers
*/

#include "server_packet_handlers.h"

const server_packet_handler_t S2C_PACKET_HANDLERS[S2C_PACKET_COUNT] = {
    [S2C_GENERIC] = &s2c_handle_generic_packet,
    [S2C_LOGIN] = &s2c_handle_login_packet,
    [S2C_LOGOUT] = &s2c_handle_logout_packet,
    [S2C_USER_LIST] = &s2c_handle_user_list_packet,
    [S2C_USER_INFO] = &s2c_handle_user_info_packet,
    [S2C_MESSAGE_LIST] = &s2c_handle_message_list_packet,
    [S2C_TEAM_LIST] = &s2c_handle_team_list_packet,
    [S2C_CHANNEL_LIST] = &s2c_handle_channel_list_packet,
    [S2C_TEAM_INFO] = &s2c_handle_team_info_packet,
    [S2C_MESSAGE_CREATED] = &s2c_handle_message_created_packet,
    [S2C_TEAM_CREATED] = &s2c_handle_team_created_packet,
    [S2C_CHANNEL_CREATED] = &s2c_handle_channel_created_packet,
    [S2C_THREAD_CREATED] = &s2c_handle_thread_created_packet,
    [S2C_COMMENT_CREATED] = &s2c_handle_comment_created_packet,
    [S2C_SUBSCRIBED] = &s2c_handle_subscribed_packet,
    [S2C_UNSUBSCRIBED] = &s2c_handle_unsubscribed_packet,
    [S2C_UNKNOWN_ITEM] = &s2c_handle_unknown_item_packet,
    [S2C_CONTEXT_UPDATE] = &s2c_handle_context_update_packet,
};
