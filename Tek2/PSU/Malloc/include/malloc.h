/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-malloc-tanguy.bellicha
** File description:
** malloc
*/

#ifndef MALLOC_H_
    #define MALLOC_H_

    #include <stdlib.h>
    #include <unistd.h>

typedef struct block_s block_t;

struct block_s {
    block_t* previous;
    block_t* next;
    int free;
    size_t size;
    void* address;
};

    #define BLOCK_SIZE sizeof(struct block_s)

void* init_memory_block(size_t size);
block_t* create_block(block_t* new_block, size_t size);
block_t* fill_block(block_t* block, size_t size);
block_t* find_block(block_t* block, size_t size);
void* malloc(size_t size);

block_t* free_block(block_t *block);
block_t* looking_for_block(block_t *block, void *ptr);
void copy_block(block_t* dest, block_t* src);

#endif/* !MALLOC_H_ */
