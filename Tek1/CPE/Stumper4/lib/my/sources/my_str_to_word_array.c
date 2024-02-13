/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** make words from string
*/

#include <stdlib.h>

int my_isnum(char c);
int my_isalpha(char c);

int is_sep(char c)
{
    if (my_isnum(c) || my_isalpha(c))
        return (0);
    return (1);
}

int is_new_word(char const *str)
{
    return (is_sep(str[0]) && !(is_sep(str[1])));
}

char *str_malloc(char const *src)
{
    char *word;
    int length = 0;
    int i = 0;

    while (is_sep(src[i]))
        i++;
    while (!(is_sep(src[i]))) {
        length++;
        i++;
    }
    word = malloc(sizeof(char) * length + 1);
    if (!(word))
        return (NULL);
    i = 0;
    length = 0;
    while (is_sep(src[i]))
        i++;
    while (!(is_sep(src[i])))
        word[length++] = src[i++];
    word[i] = '\0';
    return (word);
}

int count_words(char const *str)
{
    int i = 0;
    int c = 0;

    while (str[i]) {
        if (is_new_word(str + i) || i == 0)
            c++;
        i++;
    }
    return (c);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    int nb_words = count_words(str);
    char **split = malloc(sizeof(char *) * nb_words + 1);

    if (!str)
        return (NULL);
    while (str[i]) {
        if (is_new_word(str + i) || (i == 0 && !is_sep(str[i]))) {
            split[j] = str_malloc(str + i);
            j++;
        }
        i++;

    }
    split[j] = NULL;
    return (split);
}
