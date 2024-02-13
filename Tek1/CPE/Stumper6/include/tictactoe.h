/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper6-tanguy.bellicha
** File description:
** tictactoe
*/

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct game_s {
    char char1;
    char char2;
    int size;
    char **grid;
} game_t;

// GRID
void draw_grid(game_t *game);
void print_horizontal(game_t *game);
void print_vertical(char *line);

// INITIALIZATION
int manage_flag(game_t *game, char *flag, char *value);
game_t *check_arguments(int argc, char **argv);
int is_valid_char(char c);
char **create_grid(int size);

// DESTROY_GAME
void destroy_game(game_t *game);

// GAME
int start_game(game_t *game);
int check_win(game_t *game);
int check_draw(game_t *game);
int do_p1_turn(game_t *game);
int do_p2_turn(game_t *game);
int check_vertically(game_t *game, int i, int j);
int check_second_diag(game_t *game, int i, int j);
int check_first_diag(game_t *game, int i, int j);
int check_horizontally(game_t *game, int i, int j);

// PLAYER TURN
int do_p1_turn(game_t *game);
int do_p2_turn(game_t *game);

#endif /* !TICTACTOE_H_ */