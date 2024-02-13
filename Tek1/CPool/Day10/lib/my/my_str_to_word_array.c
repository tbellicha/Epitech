/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** desc
*/

#include "my.h"
#include <stdlib.h>

int check_alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

int count_words(char const *str)
{
    int i = 0;
    int words = 0;

    while (str[i] != 0) {
        if (check_alphanum(str[i]) == 1)
            words++;
        while (check_alphanum(str[i]) == 1 && str[i] != 0)
            i++;
        if (str[i] != 0)
            i++;
    }
    return (words);
}

int word_length(char const *str, int word_index)
{
    int length = 0;

    while (check_alphanum(str[word_index]) == 1) {
            word_index++;
            length++;
    }
    return (length);
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (count_words(str) + 1));
    int i = 0;
    int j = 0;
    int tempo = 0;

    while (i != count_words(str)) {
        j = 0;
        while (check_alphanum(str[tempo]) == 0)
            tempo++;
        array[i] = malloc(sizeof(char) * (word_length(str, j) + 1));
        while (check_alphanum(str[tempo]) == 1) {
            array[i][j] = str[tempo];
            j++;
            tempo++;
        }
        array[i][j] = 0;
        i++;
    }
    array[i] = 0;
    return (array);
}
