/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Unknown server to client packet
*/

#include "packet_handlers.h"
#include "packet_reply.h"

packet_result_t handle_unknown_packet(struct peer *peer, size_t length)
{
    reply_error(peer, REPLY_UNKNOWN_PACKET, "unknown packet", length);
    return PRESULT_OK;
}
