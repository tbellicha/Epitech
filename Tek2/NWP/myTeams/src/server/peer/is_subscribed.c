/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Whether a peer is subscribed to a team
*/

#include "items/team.h"
#include "items/user.h"
#include "peer.h"

#include <stdbool.h>

bool peer_is_subscribed(peer_t *peer, struct team *team)
{
    team_subscriber_t *sub = LIST_FIRST(&team->subscribers);
    user_t *user = peer->user;

    if (user == NULL)
        return false;
    while (sub && sub->user != user)
        sub = LIST_NEXT(sub, subscribers);
    return sub != NULL;
}
