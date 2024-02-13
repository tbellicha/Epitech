/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper4-tanguy.bellicha
** File description:
** files
*/

#include "pokemon.h"

int skip_until_char(char *str, char c)
{
    int i = 0;

    while (str[i] && str[i] != c)
        i++;
    return (++i);
}

char *get_str_until_char(char *str, char c)
{
    int i = 0;
    char *ret = NULL;

    while (str[i] && str[i] != c)
        i++;
    ret = malloc(sizeof(char) * (i + 2));
    ret = my_strncpy(ret, str, i);
    return (ret);
}

void manage_file_content(pokedex_t *pokedex, char *content)
{
    int i = 0;

    while (i < my_strlen(content) && content[i]) {
        while (content[i] == '#' && (i == 0 || content[i - 1] == '\n'))
            i += skip_until_char(&content[i], '\n');
        pokedex->list_pokemon[pokedex->nb_pokemon++] = \
            create_pokemon(get_str_until_char(&content[i], '\n'));
        i += skip_until_char(&content[i], '\n');
    }
}