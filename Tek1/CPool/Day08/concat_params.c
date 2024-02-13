/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** 
*/

#include "../Librairie/include/my.h"
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int length = 0;
    char *str;

    for (i = 0; i < argc; i++)
        length += my_strlen(argv[i]) + 1;
    str = malloc(sizeof(char) * length);
    str[0] = 0;
    for (i = 0; i < argc; i++) {
        my_strcat(str, argv[i]);
        if (i < (argc - 1))
            my_strcat(str, "\n");
    }
    return (str);
}
