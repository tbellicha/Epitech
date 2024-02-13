/*
** EPITECH PROJECT, 2025
** stump_4
** File description:
** Created by hjulien,
*/

#include "pokemon.h"

pokemon_t create_pokemon(char *info)
{
    pokemon_t new_pokemon;
    char **data = my_str_to_word_tab(info, ';');
    int i = 0;

    while (data[i])
        i++;
    if (i != 5) {
        my_putstr_err("Incomplete information on a Pokemon\n");
        exit(84);
    }
    for (int k = 1; k < 5; k++) {
        if (!my_str_isnum(data[k])) {
            my_putstr_err("Bad information on a Pokemon\n");
            exit(84);    
        }
    }
    new_pokemon.name = my_strdup(data[0]);
    new_pokemon.attack = my_getnbr(data[1]);
    new_pokemon.defense = my_getnbr(data[2]);
    new_pokemon.speed = my_getnbr(data[3]);
    new_pokemon.health = my_getnbr(data[4]);
    return (new_pokemon);
}