/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** 
*/

#include "my.h"

void display_result(char c, int count, int nb_of_letters)
{
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(count);
    my_putstr(" (");
    my_put_nbr((count * 10000) / (nb_of_letters * 100));
    my_putchar('.');
    if ((((count * 10000) % (nb_of_letters * 100)) / nb_of_letters) < 10)
        my_putchar('0');
    my_put_nbr(((count * 10000) % (nb_of_letters * 100)) / nb_of_letters);
    my_putstr("%)\n");
}

int my_char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

void count_chars(char *str, char *looking_for)
{
    int i = 0;
    int letters = 0;
    int count = 0;

    if (my_str_isupper(looking_for))
        my_strupcase(str);
    if (my_str_islower(looking_for))
        my_strlowcase(str);
    while (str[i] != '\0') {
        if (looking_for[0] == str[i])
            count++;
        if (my_char_isalpha(str[i]))
            letters++;
        i++;
    }
    display_result(looking_for[0], count, letters);
}

void rush2(int ac, char **av)
{
    int i = 0;
    char c;

    while (i < (ac - 2)) {
        count_chars(av[1], av[i + 2]);
        i++;
    }
}
