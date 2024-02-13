/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-malloc-tanguy.bellicha
** File description:
** free
*/

#include "../include/malloc.h"

block_t* free_all_previous(block_t* block)
{
    while (block->previous && block->previous->free) {
        block->previous->size += block->size + sizeof(block_t);
        block->previous->next = block->next;
        if (block->next)
            block->next->previous = block->previous;
        block = block->previous;
    }
    return (block);
}

block_t* free_all_next(block_t* block)
{
    while (block->next && block->next->free) {
        block->size += block->next->size + sizeof(block_t);
        block->next->next->previous = block;
        block->next = block->next->next;
    }
    return (block);
}

block_t* free_block(block_t* block)
{
    block_t* curr = block;

    block->free = 1;
    block = free_all_previous(block);
    block = free_all_next(block);
    if (!block->next) {
        if (block->previous)
            block->previous->next = NULL;
        else
            curr = NULL;
        sbrk((sizeof(block_t) + block->size) * -1);
    }
    return (curr);
}
