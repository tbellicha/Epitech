/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** desc
*/

#include "my.h"
#include <strings.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int char_to_lowercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}

int my_strcasecmp_lowerhigher(char *s1, char *s2)
{
    int i = 0;

    my_revstr(s1);
    my_revstr(s2);
    while (s1[i]) {
        if (s1[i] - s2[i] > 0) {
            my_revstr(s1);
            my_revstr(s2);
            return (s1[i] - s2[i]);
        }
        i++;
    }
    my_revstr(s1);
    my_revstr(s2);
    return (0);
}

int my_strcasecmp(char *s1, char *s2)
{
    int i = 0;
    int c = 0;

    while (s1[i]) {
        if (!s2[i])
            return (s1[i]);
        c = char_to_lowercase(s1[i]) - char_to_lowercase(s2[i]);
        if (c != 0)
            return (c);
        i++;
    }
    return (my_strcasecmp_lowerhigher(s1, s2));
}