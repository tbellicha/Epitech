/*
** EPITECH PROJECT, 2020
** bsprintf.h
** File description:
** desc
*/

#ifndef	BSPRINTF_H
#define BS_PRINTF_H

#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr_base_int(int nb, char const *base);
int my_put_nbr_base_long(long nb, char *base);
int convert_decimal_to_octal(int dec_nb);
int convert_decimal_to_binary(int dec_nb);
char *convertDecimalToHexa(int dec_nb);
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

#endif