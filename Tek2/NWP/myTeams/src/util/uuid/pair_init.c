/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Initializes an UUID pair
*/

#include "uuid_util.h"

#include <string.h>

void uuid_pair_init(uuid_pair_t *pair, uuid_t id_a, uuid_t id_b)
{
    if (uuid_compare(id_a, id_b) <= 0) {
        memcpy(pair->id_a, id_a, sizeof(uuid_t));
        memcpy(pair->id_b, id_b, sizeof(uuid_t));
    } else {
        memcpy(pair->id_a, id_b, sizeof(uuid_t));
        memcpy(pair->id_b, id_a, sizeof(uuid_t));
    }
}
