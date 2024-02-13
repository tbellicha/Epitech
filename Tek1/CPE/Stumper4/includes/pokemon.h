/*
** EPITECH PROJECT, 2025
** stump_4
** File description:
** Created by hjulien,
*/
#ifndef STUMP_4_POKEMON_H
#define STUMP_4_POKEMON_H

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <dirent.h>
#include <fcntl.h>
#include "my.h"

#define EXIT_ERROR 84

typedef struct pokemon_s {
    char *name;
    int attack;
    int defense;
    int speed;
    int health;
} pokemon_t;

typedef struct pokedex_s {
    pokemon_t *list_pokemon;
    int nb_pokemon;
} pokedex_t;


/**************PARSING***************/
int list_files(pokedex_t *pokedex, char *pathname);
char *load_file(char const *filepath);

/**************FILES***************/
void manage_file_content(pokedex_t *pokedex, char *content);

/**************DISPLAY**************/
void display_attack(pokemon_t *attack, pokemon_t *defend, int rand_attack);
void display_pokemon_stats(pokemon_t *pokemon);

/**************BATTLE**************/
void start_fight(pokedex_t *pokedex, int index_first_pokemon, int index_second_pokemon);

/***************UTILS***************/
int find_index_from_name(char *name, pokedex_t *pokedex);

/***************POKEMON***************/
pokemon_t create_pokemon(char *infos);

#endif //STUMP_4_POKEMON_H
