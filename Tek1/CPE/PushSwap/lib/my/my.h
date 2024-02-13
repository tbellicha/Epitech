/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include "pushswap.h"

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
char *my_strcpy(char *dest, char const *src);
void my_exception(void);
int check_alphanum(char c);

typedef struct t_lists {
    int *list_a;
    int *list_b;
    int size1;
    int size2;
} s_lists;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
char *my_strcpy(char *dest, char const *src);
void my_exception(void);
int check_alphanum(char c);
int check_args(int argc, char **argv);
s_lists *initialize_lists(int argc);
s_lists *initialize_sort(s_lists *lists, int space);
s_lists *add_in_listb(s_lists *lists);
s_lists *before_lastb_lower_than_lastb(s_lists *lists);
s_lists *put_in_a(s_lists *lists);
s_lists *put_in_b(s_lists *lists, int space);
s_lists *switch_a(s_lists *lists, int space);
s_lists *switch_b(s_lists *lists);
s_lists *rotate_a(s_lists *lists, int display);
s_lists *rotate_b(s_lists *lists, int display);
s_lists *rotate_ra(s_lists *lists, int display);
s_lists *rotate_rb(s_lists *lists, int display);
void sort_list(s_lists *lists);
int check_order(char **argv);
int check_args(int argc, char **argv);
void *free_malloc(s_lists *tempo, int i);
int check_order_list(s_lists *lists);


#endif /* !MYH_H */