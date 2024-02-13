/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-malloc-tanguy.bellicha
** File description:
** find_block
*/

#include "../include/malloc.h"

block_t* find_block(block_t* block, size_t size)
{
    if (!block)
        return (NULL);
    while (block) {
        if (block->free && block->size == size)
            return (block);
        if (block->free && block->size > BLOCK_SIZE + size + 1) {
            block->size = size;
            block->free = 0;
            block = fill_block(block, size);
            return (block);
        }
        block = block->next;
    }
    return (NULL);
}

block_t* looking_for_block(block_t* block, void* ptr)
{
    if (!ptr)
        return (NULL);
    while (block) {
        if (block->address == ptr)
            return (block);
        block = block->next;
    }
    return (NULL);
}
