/*
** EPITECH PROJECT, 2021
** LibMy - collection module internals
** File description:
** The hash map internals
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

#include "hash_map.h"

typedef struct p_my_hash_map_entry {
    uint64_t hash;
    struct p_my_hash_map_entry *next;
    char kv;
} my_hash_map_entry_t;

#define P_MY_HM_KEY(m, e) ((void *)(((char *)(e)) + (m)->key_offset))
#define P_MY_HM_VAL(m, e) ((void *)(((char *)(e)) + (m)->value_offset))

static inline int p_my_map_kvtypes_is_valid(my_map_kvtypes_t const *kvtypes)
{
    return kvtypes->key_size > 0 && kvtypes->key_align > 0
        && kvtypes->value_align > 0 && kvtypes->compare != NULL;
}

int p_my_hash_map_init_buckets(my_hash_map_t *map);

void p_my_hash_map_cstr_drop(char **str);
int p_my_hash_map_cstr_cmp(char **str_1, char **str_2);
void p_my_hash_map_cstr_hash(my_hasher_t *hasher, char **str);

void *my_calloc(size_t nmemb, size_t size);
