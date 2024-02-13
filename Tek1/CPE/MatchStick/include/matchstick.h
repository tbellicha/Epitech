/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-bsmatchstick-tanguy.bellicha
** File description:
** .h
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct matchstick {
    int ret;
    int nb_line_base;
    int max_matches;
    int *board_base;
    int *current_board;
} s_matchstick;

void ai_turn(s_matchstick *matchstick);
int looking_for_best_move(s_matchstick *matchstick);

int player_turn(s_matchstick *matchstick, int display);
int read_input(s_matchstick *matchstick, int line_matches, int nm_line);

int print_error(int index, s_matchstick *matchstick);
void print_n_chars(char c, int nb);
void draw_board(s_matchstick *matchstick);

#endif /* !MATCHSTICK_H_ */