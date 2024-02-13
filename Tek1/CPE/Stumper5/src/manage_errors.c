/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-tanguy.bellicha
** File description:
** check
*/

#include "hangman.h"

int check_errors(int ac)
{
    if (ac != 2 && ac != 3) {
        my_putstr_err("Invalid number of arguments\n");
        return (0);
    }
    return (1);
}

int check_multiple_word_per_line(char *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] == ' ')
            return (0);
        i++;
    }
    return (1);
}

int check_length_of_words(char **array)
{
    int i = 0;

    while (array[i]) {
        if (my_strlen(array[i]) < 1)
            return (0);
        i++;
    }
    return (1);
}