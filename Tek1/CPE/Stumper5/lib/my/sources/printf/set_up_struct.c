/*
** EPITECH PROJECT, 2020
** set_up_struct.c
** File description:
** set up all the ptr functions
*/

#include "flags.h"
#include "my_printf.h"

void set_up_ptr_fonc_first_part(which_flag_t *which_flag)
{
    which_flag[0].flag = '+';
    which_flag[0].fonc_ptr = &plus_flag;
    which_flag[1].flag = '-';
    which_flag[1].fonc_ptr = &minus_flag;
    which_flag[2].flag = '%';
    which_flag[2].fonc_ptr = &mod_flag;
    which_flag[3].flag = 'i';
    which_flag[3].fonc_ptr = &i_flag;
    which_flag[4].flag = 'd';
    which_flag[4].fonc_ptr = &d_flag;
    which_flag[5].flag = 'u';
    which_flag[5].fonc_ptr = &u_flag;
    which_flag[6].flag = 'c';
    which_flag[6].fonc_ptr = &c_flag;
    which_flag[7].flag = 's';
    which_flag[7].fonc_ptr = &s_flag;
    which_flag[8].flag = 'S';
    which_flag[8].fonc_ptr = &cap_s_flag;
}

void set_up_ptr_fonc_second_part(which_flag_t *which_flag)
{
    which_flag[9].flag = 'p';
    which_flag[9].fonc_ptr = &p_flag;
    which_flag[10].flag = 'b';
    which_flag[10].fonc_ptr = &b_flag;
    which_flag[11].flag = 'x';
    which_flag[11].fonc_ptr = &x_flag;
    which_flag[12].flag = 'X';
    which_flag[12].fonc_ptr = &cap_x_flag;
    which_flag[13].flag = 'o';
    which_flag[13].fonc_ptr = &o_flag;
}

void set_up_hashtag_ptr_fonc_first_part(which_flag_t *which_hashtag_flag)
{
    which_hashtag_flag[0].flag = '+';
    which_hashtag_flag[0].fonc_ptr = &plus_flag;
    which_hashtag_flag[1].flag = '-';
    which_hashtag_flag[1].fonc_ptr = &minus_flag;
    which_hashtag_flag[2].flag = '%';
    which_hashtag_flag[2].fonc_ptr = &mod_flag;
    which_hashtag_flag[3].flag = 'i';
    which_hashtag_flag[3].fonc_ptr = &i_flag;
    which_hashtag_flag[4].flag = 'd';
    which_hashtag_flag[4].fonc_ptr = &d_flag;
    which_hashtag_flag[5].flag = 'u';
    which_hashtag_flag[5].fonc_ptr = &u_flag;
    which_hashtag_flag[6].flag = 'c';
    which_hashtag_flag[6].fonc_ptr = &c_flag;
    which_hashtag_flag[7].flag = 's';
    which_hashtag_flag[7].fonc_ptr = &s_flag;
    which_hashtag_flag[8].flag = 'S';
    which_hashtag_flag[8].fonc_ptr = &cap_s_flag;
}

void set_up_hashtag_ptr_fonc_second_part(which_flag_t *which_hashtag_flag)
{
    which_hashtag_flag[9].flag = 'p';
    which_hashtag_flag[9].fonc_ptr = &p_flag;
    which_hashtag_flag[10].flag = 'b';
    which_hashtag_flag[10].fonc_ptr = &b_flag;
    which_hashtag_flag[11].flag = 'x';
    which_hashtag_flag[11].fonc_ptr = &x_hashtag_flag;
    which_hashtag_flag[12].flag = 'X';
    which_hashtag_flag[12].fonc_ptr = &cap_x_hashtag_flag;
    which_hashtag_flag[13].flag = 'o';
    which_hashtag_flag[13].fonc_ptr = &o_hashtag_flag;
}
