/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-tanguy.bellicha
** File description:
** ai
*/

#include "matchstick.h"

int get_number_index(int number, int index)
{
    char *str = my_itoa(number);

    if (my_strlen(str) <= index)
        return (0);
    return (str[index] - '0');
}

int calcul_column(int *binary_values, int column)
{
    int result = 0;

    for (int i = 0; binary_values[i]; i++)
        result += get_number_index(binary_values[i], column);
    return (result % 2);

}

int looking_for_best_move(s_matchstick *matchstick)
{
    int *binary_values = malloc(sizeof(int) * matchstick->nb_line_base);
    int binary_addition_result = 0;

    for (int i = 0; i < matchstick->nb_line_base; i++)
        binary_values[i] = \
        convert_decimal_to_binary(matchstick->current_board[i]);
    for (int i = 0; i < matchstick->nb_line_base; i++)
        binary_addition_result += calcul_column(binary_values, i) * \
        my_compute_power_rec(2, i);
    for (int i = 0; matchstick->current_board[i]; i++) {
        if (matchstick->current_board[i] >= binary_addition_result \
        && binary_addition_result <= matchstick->max_matches \
        && binary_addition_result != 0) {
            matchstick->current_board[i] -= binary_addition_result;
            my_printf("\nAI's turn...\nAI removed %d \
match(es) from line %d\n", binary_addition_result, i + 1);
            return (1);
        }
    }
    return (0);
}

void ai_turn(s_matchstick *matchstick)
{
    int random_line = 0;
    int random_matches = 0;

    if (looking_for_best_move(matchstick)) {
        draw_board(matchstick);
        return ;
    }
    while (1) {
        random_line = (random() % matchstick->nb_line_base) + 1;
        if (matchstick->current_board[random_line - 1] == 0)
            continue;
        random_matches = (random() % matchstick->max_matches) + 1;
        if (!(matchstick->current_board[random_line - 1] < random_matches)) {
            matchstick->current_board[random_line - 1] -= random_matches;
            my_printf("\nAI's turn...\nAI removed %d \
match(es) from line %d\n", random_matches, random_line);
            draw_board(matchstick);
            return ;
        }
    }
}