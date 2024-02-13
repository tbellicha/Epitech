/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-tanguy.bellicha
** File description:
** check_first_line
*/

#include "my.h"

t_my_bsq update_buffer(t_my_bsq buffer, int **arr, int k, int i)
{
    buffer.value = arr[k][i];
    buffer.line = k;
    buffer.col = i;
    return (buffer);
}

t_my_bsq check_first_line(t_my_bsq buffer, int **arr)
{
    int i = 0;

    while (arr[0][i] == 0)
        i++;
    if (arr[0][i] == 1) {
        buffer.value = 1;
        buffer.line = 0;
        buffer.col = i;
    }
    return (buffer);
}