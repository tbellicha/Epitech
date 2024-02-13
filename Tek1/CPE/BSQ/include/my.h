/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#define c_to_i(c) (c - 48)

typedef struct struct_my_bsq
{
    int value;
    int line;
    int col;
} t_my_bsq;

t_my_bsq check_first_line(t_my_bsq, int **);
t_my_bsq update_buffer(t_my_bsq, int **, int, int);
t_my_bsq dump_arr(t_my_bsq, char **, int **);
char **fill_map_with_x(char **, t_my_bsq);
int make_and_display_tab(char *, int, int);
int	get_size_line_int(char **tab, int k);
int	**get_size_first_line_tab(char **tab, int **arr);
int cond(int **, int, int);
void my_putchar(char);
void my_putstr(char *);
void my_put_tab(char **);
char **my_str_to_word_tab(char *, char **, int);
int get_horizontal_length(char *, int);
int my_getnbr(char const *);
int my_strlen(char *);
int check_map(char **array, int length, int width);
int check_char(char **array, int i, int k, int length);

#endif /* !MY_H_ */