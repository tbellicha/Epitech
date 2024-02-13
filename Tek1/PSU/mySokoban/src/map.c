/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-tanguy.bellicha
** File description:
** map
*/

#include "my.h"
#include "sokoban.h"

char **reset_map(char **base_map, int max_height)
{
    char **tab = malloc(sizeof(char *) * (max_height + 1));

    for (int i = 0; base_map[i]; i++)
        tab[i] = my_strdup(base_map[i]);
    return (tab);
}

void display_map(s_soko *soko)
{
    for (int i = 0; soko->map[i]; i++) {
        mvprintw((LINES / 2) - (soko->max_height / 2) + i, \
        (COLS / 2) - (soko->max_width / 2), soko->map[i]);
    }
    refresh();
}

void initialize_game(s_soko *soko, char *str)
{
    soko->map = my_str_to_word_array(str);
    soko->base_map = my_str_to_word_array(str);
    soko->nb_o = 0;
    get_stats_of_map(soko);
    initscr();
    noecho();
    curs_set(0);
    cbreak();
    keypad(stdscr, TRUE);
}