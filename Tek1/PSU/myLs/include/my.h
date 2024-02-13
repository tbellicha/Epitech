/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <dirent.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define char_is_upp(c) (c >= 'A' && c <= 'Z')? 1 : 0
#define char_is_low(c) (c >= 'a' && c <= 'z')? 1 : 0

typedef struct t_struct_my_ls {
    int lsr;
    int lsR;
    int lsl;
    int lst;
    int lsd;
    int valid;
} s_my_ls;

void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(char **str1, char **str2);
char *my_strupcase(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
int my_strcmp_lowercase(char *s1, char *s2);
int my_strcasecmp(char *s1, char *s2);
char *my_strcpy(char *dest, char *src);
char *my_revstr(char *str);
int my_put_nbr_base_int(int nb, char const *base);
int my_put_nbr_base_long(long nb, char *base);
int convert_decimal_to_octal(int dec_nb);
int convert_decimal_to_binary(int dec_nb);
char *convert_decimal_to_hexa(int dec_nb);
int my_put_adress(long long nb);
int my_get_number_after_commas(float nb);
double float_modulo(double nb, double mod);
int my_switch_numbers(char *str, va_list args, int i);
int my_switch_alpha(char *str, va_list args, int i);
int my_switch_hexbin(char *str, va_list args, int i);
int my_switch_hash(char *str, va_list args, int i);
void my_put_unsigned(unsigned int nb);
void my_put_ascii(int nb);
void my_putstr_np(char *str);
void put_zeros(char *str, int i);
void my_printf(char *str, ...);
void my_swap_int_array(int *number1, int *number2);
int my_ls_without_flag(DIR *directory);
int print_error_access(int value, char *arg);
int get_type(char *str);
char **sort_alphabetically(char **tab_dir_files);
char **sort_alphabetically_reversed(char **tab_dir_files);
char ***sort_alphabetically_triple(char ***ls, int nb_line, int order);
s_my_ls detect_flags(s_my_ls params, char *str);
s_my_ls switch_param(s_my_ls param, char p);
void display_result(char *dirpath, s_my_ls params);
s_my_ls reset_params(void);
char *int_to_str(int i);
char *my_strcatchar(char *dest, char c);
void my_put_tab(char **tab, char *parser, int limit);
char **fill_file_infos(struct stat stat_s, struct dirent *dirent_s);
int my_get_total_blocks(char ***ls, int lines);
char *get_perms(struct stat stat);
char *get_time(char *str);

#endif /* !MY_H_ */