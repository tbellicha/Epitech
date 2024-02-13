/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-tanguy.bellicha
** File description:
** main
*/

#include "matchstick.h"

int check_if_ended(s_matchstick *matchstick, int player)
{
    for (int i = 0; i < matchstick->nb_line_base; i++)
        if (matchstick->current_board[i] > 0)
            return (0);
    if (player == 1)
        my_printf("You lost, too bad...\n");
    my_printf("I lost... snif... but I'll get you next time!!\n");
    return (1);
}

s_matchstick *initialize_board(int argc, char **argv)
{
    s_matchstick *matchstick = malloc(sizeof(s_matchstick));

    if (matchstick == NULL || (argc != 3 || !(my_getnbr(argv[1]) > 0 \
    && my_getnbr(argv[1]) < 100) || !(my_getnbr(argv[2]) > 0))) {
        return (NULL);
    }
    matchstick->nb_line_base = my_getnbr(argv[1]);
    matchstick->max_matches = my_getnbr(argv[2]);
    if ((matchstick->board_base = \
    malloc(sizeof(int) * matchstick->nb_line_base)) == NULL)
        return (NULL);
    for (int i = 0; i < matchstick->nb_line_base; i++)
        matchstick->board_base[i] = (i + 1) * 2 - 1;
    matchstick->current_board = matchstick->board_base;
    return (matchstick);
}

int main(int argc, char **argv)
{
    s_matchstick *matchstick = initialize_board(argc, argv);
    int first = 1;

    if (matchstick == NULL)
        return (84);
    draw_board(matchstick);
    while (1) {
        if ((matchstick->ret = player_turn(matchstick, first)) == 0) {
            first = 0;
            continue;
        }
        if (matchstick->ret == -1)
            return (0);
        if (check_if_ended(matchstick, 1))
            return (2);
        ai_turn(matchstick);
        if (check_if_ended(matchstick, 2))
            return (1);
        first = 1;
    }
}