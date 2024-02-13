/*
** EPITECH PROJECT, 2025
** stump5
** File description:
** Created by hjulien,
*/
#ifndef STUMP5_HANGMAN_H
#define STUMP5_HANGMAN_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <stdbool.h>

typedef enum CONDITIONS_E
{
    win,
    lose,
    error
} CONDITIONS_T;

typedef struct dico_s
{
    char **array_words;
    int tries;
    int nb_words;
} dico_t;

typedef struct game_s
{
    dico_t *dico;
    bool win;
    char *word;
    char *hidden_word;
    char current_letter;
} game_t;

/*********GAME**********/
game_t *game_init(int ac, char **av);
int game_loop(game_t *game);

/*********UTILS*********/
void free_game(game_t *game);

/*********DICO*********/
dico_t *load_dico(int ac, char **av);

/********DISPLAY*********/
void display_running_game(game_t *game);
void display_pre_game(game_t *game);

/*******PLAYER_TURN********/
void make_player_turn(game_t *game);

int get_file_size(const char *pathname);
char *file_to_string(const char *pathname);
int check_errors(int ac);
int check_multiple_word_per_line(char *str);
int check_length_of_words(char **array);

#endif //STUMP5_HANGMAN_H
