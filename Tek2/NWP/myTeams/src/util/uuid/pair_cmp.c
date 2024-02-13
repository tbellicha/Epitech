/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** UUID pair comparison
*/

#include "uuid_util.h"

int uuid_pair_cmp(uuid_pair_t const *a, uuid_pair_t const *b)
{
    int ret = uuid_compare(a->id_a, b->id_a);

    if (ret != 0)
        return ret;
    return uuid_compare(a->id_b, b->id_b);
}
