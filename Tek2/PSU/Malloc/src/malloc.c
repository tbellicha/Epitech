/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-malloc-tanguy.bellicha
** File description:
** malloc
*/

#include "../include/malloc.h"

static block_t* base = NULL;

void* malloc(size_t size)
{
    block_t* current;

    if (!size)
        return (NULL);
    if (!base) {
        if ((base = init_memory_block(size)))
            return (base->address);
        return (NULL);
    }
    current = find_block(base, size);
    if (current) {
        current->free = 0;
        return (current->address);
    } else {
        current = create_block(base, size);
        if (current)
            return (current->address);
        return (NULL);
    }
    return (NULL);
}

void free(void* to_free)
{
    block_t* current = base;
    int tmp = 0;

    if (to_free == NULL)
        return;
    while (current) {
        if (current->address == to_free)
            tmp = 1;
        if (current->address == to_free && free_block(current) == NULL)
            base = NULL;
        if (tmp == 1)
            return;
        current = current->next;
    }
}

void* calloc(size_t nb, size_t size)
{
    int *ptr = malloc(size * nb);

    if (ptr == NULL)
        return (NULL);
    for (int i = 0; i < (int) size; i++)
        ptr[i] = 0;
    return (ptr);
}

void* realloc(void* ptr, size_t size)
{
    void* dest = malloc(size);
    block_t* start;
    block_t* end;

    if (!dest) {
        free(ptr);
        return (NULL);
    }
    end = looking_for_block(base, ptr);
    start = looking_for_block(base, dest);
    if (!end || !start)
        return (dest);
    copy_block(start, end);
    free(ptr);
    return (dest);
}
