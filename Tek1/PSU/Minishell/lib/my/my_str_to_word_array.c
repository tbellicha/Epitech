/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** desc
*/

#include "my.h"
#include <stdlib.h>

int count_words(char *str, char *delims)
{
    int words = 0;

    while (*str) {
        while (*str && my_char_is_in_string(delims, *str))
            str++;
        words += ((*str) != 0);
        while (*str && !my_char_is_in_string(delims, *str))
            str++;
    }
    return (words);
}

char **my_str_to_word_array(char *str, char *delims)
{
    int count = count_words(str, delims);
    char **array = malloc(sizeof(char *) * (count + 1));
    int start;
    int i = 0;
    int w = 0;

    while (str[i]) {
        while (str[i] && my_char_is_in_string(delims, str[i]))
            i++;
        start = i;
        while (str[i] && !my_char_is_in_string(delims, str[i]))
            i++;
        array[w] = malloc(sizeof(char) * (i - start + 1));
        my_strncpy(array[w], str + start, (i - start));
        array[w++][i - start] = 0;
    }
    array[w] = NULL;
    return (array);
}