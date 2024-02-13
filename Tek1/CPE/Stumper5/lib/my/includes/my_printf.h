/*
** EPITECH PROJECT, 2020
** my_printf.h
** File description:
** lib for my_printf.h
*/

#include "flags.h"

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

void set_up_ptr_fonc_first_part(which_flag_t *which_flag);
void set_up_ptr_fonc_second_part(which_flag_t *which_flag);
int i_flag(va_list args, ...);
int d_flag(va_list args, ...);
int c_flag(va_list args, ...);
int s_flag(va_list args, ...);
int p_flag(va_list args, ...);
int b_flag(va_list args, ...);
int x_flag(va_list args, ...);
int cap_x_flag(va_list args, ...);
int o_flag(va_list args, ...);
int plus_flag(va_list args, ...);
int minus_flag(va_list args, ...);
int mod_flag(va_list args, ...);
int u_flag(va_list args, ...);
int cap_s_flag(va_list args, ...);
void set_up_hashtag_ptr_fonc_first_part(which_flag_t *which_hashtag_flag);
void set_up_hashtag_ptr_fonc_second_part(which_flag_t *which_hashtag_flag);
int x_hashtag_flag(va_list args, ...);
int cap_x_hashtag_flag(va_list args, ...);
int o_hashtag_flag(va_list args, ...);

#endif
