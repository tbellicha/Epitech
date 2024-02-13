/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04am-tanguy.bellicha
** File description:
** print
*/

#include <stdio.h>
#include <string.h>
#include "./print.h"
#include <ctype.h>

void print_normal(const char *str)
{
    puts(str);
    putchar('\n');
}

void print_reverse(const char *str)
{
    for (int i = strlen(str); i >= 0; i--)
        printf("%c", str[i]);
    putchar('\n');
}

void print_upper(const char *str)
{
    for (int i = 0; i < strlen(str); i++)
        printf("%c", toupper(str[i]));
    putchar('\n');
}

void print_42(const char *str)
{
    puts("42");
    putchar('\n');
}

void do_action(action_t action, const char *str)
{
    void(*which_print[]) (const char *) = {&print_normal, \
        &print_reverse, &print_upper, &print_42};
    which_print[action](str);
}
