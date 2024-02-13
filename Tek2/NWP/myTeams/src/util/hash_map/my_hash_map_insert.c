/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Inserts a key-value pair into a hash map
*/

#include "hash_map.h"

my_map_err_t my_hash_map_insert(my_hash_map_t *map, void *key, void *value)
{
    if (my_hash_map_insert_entry(map, key, value) != NULL || value == NULL)
        return MY_MAP_OK;
    return MY_MAP_ALLOC;
}
