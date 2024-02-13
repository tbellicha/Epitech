/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-malloc-tanguy.bellicha
** File description:
** block
*/

#include "../include/malloc.h"

void* init_memory_block(size_t size)
{
    block_t* new_block;
    void* address = sbrk(BLOCK_SIZE + size);

    if (address == (void*) -1)
        return (NULL);
    new_block = address;
    new_block->address = (char*) address + BLOCK_SIZE;
    new_block->free = 0;
    new_block->previous = NULL;
    new_block->next = NULL;
    new_block->size = size;
    return (new_block);
}

block_t* create_block(block_t* new_block, size_t size)
{
    void* address;

    while (new_block->next)
        new_block = new_block->next;
    address = sbrk(BLOCK_SIZE + size);
    if (address == (void*) -1)
        return (NULL);
    new_block->next = address;
    new_block->next->address = (char*) address + BLOCK_SIZE;
    new_block->next->free = 0;
    new_block->next->previous = new_block;
    new_block->next->next = NULL;
    new_block->next->size = size;
    return (new_block->next);
}

block_t* fill_block(block_t* block, size_t size)
{
    int total = block->size - size;
    void* tmp = block->next;

    block->next = block->address + size;
    block->next->address = BLOCK_SIZE + block->next;
    block->next->size = total;
    block->next->next = tmp;
    block->next->previous = block;
    block->next->free = 1;
    return (block);
}

void copy_block(block_t* dest, block_t* src)
{
    size_t* p_dest;
    size_t* p_src;
    size_t x = sizeof(size_t);

    p_dest = (size_t*) dest->address;
    p_src = (size_t*) src->address;
    for (int i = 0; (i * x) < src->size && (i * x) < dest->size; i++)
        p_dest[i] = p_src[i];
}
