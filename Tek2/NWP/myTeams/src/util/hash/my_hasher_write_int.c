/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Writes integers to a hasher
*/

#include "hash.h"

void my_hasher_write_ushort(my_hasher_t *hasher, unsigned short num)
{
    my_hasher_write(hasher, sizeof(num), &num);
}

void my_hasher_write_uint(my_hasher_t *hasher, unsigned int num)
{
    my_hasher_write(hasher, sizeof(num), &num);
}

void my_hasher_write_ulong(my_hasher_t *hasher, unsigned long num)
{
    my_hasher_write(hasher, sizeof(num), &num);
}

void my_hasher_write_ulong_long(my_hasher_t *hasher, unsigned long long num)
{
    my_hasher_write(hasher, sizeof(num), &num);
}

void my_hasher_write_size_t(my_hasher_t *hasher, size_t num)
{
    my_hasher_write(hasher, sizeof(num), &num);
}
