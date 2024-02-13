/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Packets handlers
*/

#include "packet_handlers.h"

const packet_handler_t PACKET_HANDLERS[C2S_PACKET_COUNT] = {
    [C2S_LOGIN] = &handle_login_packet,
    [C2S_LOGOUT] = &handle_logout_packet,
    [C2S_GET_USERS] = &handle_get_users_packet,
    [C2S_GET_USER_INFO] = &handle_get_user_info_packet,
    [C2S_SEND_MESSAGE] = &handle_message_packet,
    [C2S_GET_MESSAGES] = &handle_get_messages_packet,
    [C2S_SUBSCRIBE_TEAM] = &handle_subscribe_team_packet,
    [C2S_GET_SUBSCRIBED_TEAMS] = &handle_get_subscribed_teams_packet,
    [C2S_GET_TEAM_USERS] = &handle_get_team_users_packet,
    [C2S_UNSUBSCRIBE_TEAM] = &handle_unsubscribe_team_packet,
    [C2S_CREATE_ITEM] = &handle_create_item_packet,
    [C2S_GET_TEAMS] = &handle_get_teams_packet,
    [C2S_GET_CHANNELS] = &handle_get_channels_packet,
    [C2S_GET_THREADS] = &handle_get_threads_packet,
    [C2S_GET_COMMENTS] = &handle_get_comments_packet,
    [C2S_GET_TEAM_INFO] = &handle_get_team_info_packet,
    [C2S_SET_CONTEXT] = &handle_set_context_packet,
};
