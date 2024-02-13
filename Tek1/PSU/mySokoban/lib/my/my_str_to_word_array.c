/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** desc
*/

#include "my.h"
#include <stdlib.h>

int check_end(char c)
{
    if (c == '\n' || c == '\0')
        return (1);
    else
        return (0);
}

int count_words(char const *str)
{
    int i = 0;
    int words = 0;

    while (str[i] != 0) {
        if (str[i] == '\n' || str[i] == '\0')
            words++;
        i++;
    }
    words++;
    return (words);
}

void my_put_tab(char **arg)
{
    while (*arg) {
        my_putstr(*arg);
        my_putchar('\n');
        arg++;
    }
}

int word_length(char const *str)
{
    int length = 0;

    while (str[length] != '\n' && str[length] != '\0')
        length++;
    return (length);
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (count_words(str) + 1));
    int i = 0;
    int k = 0;
    int tempo = 0;

    while (str[tempo]) {
        k = 0;
        array[i] = malloc(sizeof(char) * (word_length(&str[tempo]) + 2));
        while (!(str[tempo] == '\n' || str[tempo] == '\0')) {
            array[i][k] = str[tempo];
            k++;
            tempo++;
        }
        array[i][k] = 0;
        i++;
        tempo++;
    }
    array[i] = 0;
    return (array);
}
