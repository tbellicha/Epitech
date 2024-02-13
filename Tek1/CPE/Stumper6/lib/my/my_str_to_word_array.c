/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** string to word in array
*/

#include <stdlib.h>

int len_of_word(char const *str, int index)
{
    int count = 0;

    for (; !((str[index] < '0' || str[index] > '9') && \
(str[index] < 'a' || str[index] > 'z') && \
(str[index] < 'A' || str[index] > 'Z')); index++)
        count++;
    return (count);
}

int get_word_number(char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && \
(str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            count++;
    }
    return (count + 1);
}

char **my_str_to_word_array(char const *str)
{
    int count_word = get_word_number(str);
    int index = 0;
    int len_word = 0;
    char **arr = malloc(sizeof(char *) * (count_word + 1));
    int i = 0;

    for (i = 0; i < count_word; i++) {
        len_word = len_of_word(str, index);
        arr[i] = malloc(sizeof(char) * (len_word + 1));
        index += len_word + 1;
    }
    for (i = 0, index = 0; i < count_word; i++) {
        len_word = len_of_word(str, index);
        for (int j = 0; j < len_word; j++, index++) {
            arr[i][j] = str[index];
        }
        index++;
    }
    arr[i] = NULL;
    return (arr);
}
