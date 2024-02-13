/*
** EPITECH PROJECT, 2020
** my_print_params
** File description:
** 
*/

#include "../../Librairie/include/my.h"

int main(int argc, char *argv[])
{
    int i = 0;
    
    for (; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
