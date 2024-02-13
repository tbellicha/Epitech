/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-tanguy.bellicha
** File description:
** player
*/

#include "matchstick.h"

int check_input_matches(char *input, s_matchstick *matchstick, int nm_line)
{
    if (!my_str_isnum(input)) {
        my_printf("Invalid number : |%S| %S\n", input, "\n");
        return (print_error(0, matchstick));
    }
    if (my_getnbr(input) <= 0)
        return (print_error(2, matchstick));
    (void) nm_line;
    if (my_getnbr(input) > matchstick->current_board[nm_line])
        return (print_error(3, matchstick));
    if (my_getnbr(input) > matchstick->max_matches)
        return (print_error(4, matchstick));
    return (0);
}

int check_input_line(char *input, s_matchstick *matchstick)
{
    input[my_strlen(input) - 1] = 0;
    if (!my_str_isnum(input))
        return (print_error(0, matchstick));
    if (my_getnbr(input) <= 0 || my_getnbr(input) > matchstick->nb_line_base)
        return (print_error(1, matchstick));
    return (0);
}

int read_input(s_matchstick *matchstick, int line_matches, int nm_line)
{
    char *input = NULL;
    size_t length = 0;
    ssize_t read = 0;

    if (line_matches == 0) {
        read = getline(&input, &length, stdin);
        if (read == -1)
            return (-2);
        if (check_input_line(input, matchstick) == -1)
            return (-1);
        return (my_getnbr(input) - 1);
    } else {
        read = getline(&input, &length, stdin);
        if (read == -1)
            return (-2);
        if (check_input_matches(input, matchstick, nm_line) == -1)
            return (-1);
        return (my_getnbr(input));
    }
}

int player_turn(s_matchstick *matchstick, int display)
{
    int nm_line = 0;
    int nb_matchstick = 0;

    if (display)
        my_printf("\nYour turn:\n");
    my_printf("Line: ");
    if ((nm_line = read_input(matchstick, 0, 0)) == -1)
        return (0);
    if (nm_line == -2)
        return (-1);
    my_printf("Matches: ");
    if ((nb_matchstick = read_input(matchstick, 1, nm_line)) == -1)
        return (0);
    if (nb_matchstick == -2)
        return (-1);
    my_printf("Player removed %d match(es) from line %d\n", \
    nb_matchstick, nm_line + 1);
    matchstick->current_board[nm_line] -= nb_matchstick;
    draw_board(matchstick);
    return (1);
}