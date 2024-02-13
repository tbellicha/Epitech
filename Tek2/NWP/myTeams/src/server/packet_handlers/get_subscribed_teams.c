/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** C2S_GET_SUBSCRIBED_TEAMS
*/

#include "packet_handlers.h"
#include "packet_reply.h"

packet_result_t handle_get_subscribed_teams_packet(
    peer_t *peer, size_t length)
{
    if (length != 0) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "subscribed teams packet should be empty", length);
        return PRESULT_OK;
    }
    reply_team_list(peer, true);
    return PRESULT_OK;
}
