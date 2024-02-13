/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** UUID pair hashing
*/

#include "uuid_util.h"

void uuid_pair_hash(my_hasher_t *restrict hasher, uuid_pair_t const *pair)
{
    my_hasher_write(hasher, sizeof(*pair), pair);
}
