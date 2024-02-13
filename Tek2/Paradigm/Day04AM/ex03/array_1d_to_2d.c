/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04am-tanguy.bellicha
** File description:
** array_1d_to_2d
*/

#include <stddef.h>
#include "stdlib.h"
#include "stdio.h"

void array_1d_to_2d\
(const int *array, size_t height, size_t width, int ***res)
{
    *res = malloc(sizeof(size_t) * (height + 1));
    if (res == NULL)
        return;
    for (int line = 0; line < height; line++) {
        (*res)[line] = malloc(sizeof(size_t) * (width + 1));
        for (int column = 0; column < width; column++) {
            (*res)[line][column] = array[line * width + column];
        }
    }
}

void array_2d_free(int **array_2d, size_t height, size_t width)
{
    if (array_2d == NULL)
        return;
    for (int line = 0; line < height; line++) {
        for (int column = 0; column < width; column++)
            free(array_2d[line][column]);
        free(array_2d[line]);
    }
}
