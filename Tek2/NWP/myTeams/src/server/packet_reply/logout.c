/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Logout response packet
*/

#include "peer.h"
#include "packet_reply.h"

void reply_logout(peer_t *peer, uuid_t id, char const *name)
{
    reply_login_logout(peer, id, name, S2C_LOGOUT);
}
