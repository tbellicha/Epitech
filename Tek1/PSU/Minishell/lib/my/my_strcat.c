/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** desc
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    char *ret = NULL;
    int i = -1;
    int j = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    if ((ret = malloc(sizeof(char) * (my_strlen(dest) +
        my_strlen(src) + 2))) == NULL)
        return (NULL);
    while (dest[++i] != '\0')
        ret[i] = dest[i];
    while (src[j] != '\0')
        ret[i++] = src[j++];
    ret[i] = '\0';
    return (ret);
}