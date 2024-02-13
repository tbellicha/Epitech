/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-tanguy.bellicha
** File description:
** bsq
*/

#include <stdlib.h>
#include "my.h"

int	set_value_point(int **arr, int k, int i)
{
    int top = 0;
    int left = 0;
    int top_left = 0;

    if (i == 0)
        return (1);
    else {
        top = arr[k - 1][i];
        left = arr[k][i - 1];
        top_left = arr[k - 1][i - 1];
        if (top <= left && top <= top_left)
            return (top + 1);
        else if (left <= top && left <= top_left)
            return (left + 1);
        return (top_left + 1);
    }
}

t_my_bsq set_array_int(t_my_bsq buffer, char **tab, int **arr)
{
    int i = 0;
    int k = 1;

    buffer = check_first_line(buffer, arr);
    while (tab[k]) {
        i = 0;
        arr[k] = malloc(sizeof(int) * (my_strlen(tab[k]) + 1));
        while (tab[k][i]) {
            tab[k][i] == '.' ? arr[k][i] = set_value_point(arr, k, i) : 0;
            tab[k][i] == 'o' ? arr[k][i] = 0 : 0;
            if (buffer.value < arr[k][i])
                buffer = update_buffer(buffer, arr, k, i);
            i++;
        }
        k++;
    }
    return (buffer);
}

int	get_size_line_int(char **tab, int k)
{
    int size = 0;

    while (tab[k][size] != ('\n' && '\0'))
        size++;
    return (size);
}

int	**get_size_first_line_tab(char **tab, int **arr)
{
    int	i = 0;

    arr[0] = malloc(sizeof(int) * my_strlen(tab[0]));
    while (tab[0][i] != '\n') {
        if (tab[0][i] == 'o')
            arr[0][i] = 0;
        else if (tab[0][i] == '.')
            arr[0][i] = 1;
        i++;
    }
    return (arr);
}

int make_and_display_tab(char *str, int count, int display)
{
    char **tab = 0;
    int **arr = 0;
    t_my_bsq buffer;

    buffer.value = 0;
    tab = my_str_to_word_tab(str, tab, count);
    if (check_map(tab, get_size_line_int(tab, 0) - 1, count) == 84)
        return (84);
    if (display == 1) {
        arr = malloc(sizeof(int *) * count);
        arr = get_size_first_line_tab(tab, arr);
        buffer = set_array_int(buffer, tab, arr);
        tab = fill_map_with_x(tab, buffer);
        my_put_tab(tab);
    }
    return (0);
}