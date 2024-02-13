/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Removes an entry from the hash map
*/

#include <stdlib.h>

#include "hash_map.h"

static void my_hash_map_remove_bucket(
    my_hash_map_t *map, my_hash_map_entry_t **bucket)
{
    my_hash_map_entry_t *entry;
    my_hash_map_entry_t *next = *bucket;

    do {
        entry = next;
        next = entry->next;
        if (map->key_drop)
            (*map->key_drop)(P_MY_HM_KEY(map, entry));
        if (map->value_drop)
            (*map->value_drop)(P_MY_HM_VAL(map, entry));
        free(entry);
    } while (next != NULL);
    *bucket = NULL;
}

void my_hash_map_drop(my_hash_map_t *map)
{
    assert(map != NULL);
    if (map->buckets == NULL || map->capacity == 0)
        return;
    for (size_t i = 0; i < map->capacity; ++i) {
        my_hash_map_entry_t **bucket = map->buckets + i;

        if (*bucket != NULL)
            my_hash_map_remove_bucket(map, bucket);
    }
    free(map->buckets);
    map->length = 0;
    map->capacity = 0;
}
