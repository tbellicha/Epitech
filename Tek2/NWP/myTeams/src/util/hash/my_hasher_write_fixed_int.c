/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Writes fixed-size integers to a hasher
*/

#include "hash.h"

void my_hasher_write_u8(my_hasher_t *hasher, uint8_t num)
{
    my_hasher_write(hasher, 1, &num);
}

void my_hasher_write_u16(my_hasher_t *hasher, uint16_t num)
{
    my_hasher_write(hasher, 2, &num);
}

void my_hasher_write_u32(my_hasher_t *hasher, uint32_t num)
{
    my_hasher_write(hasher, 4, &num);
}

void my_hasher_write_u64(my_hasher_t *hasher, uint64_t num)
{
    my_hasher_write(hasher, 8, &num);
}
