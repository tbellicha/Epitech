/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-tanguy.bellicha
** File description:
** switch_flags
*/

#include "my.h"

s_my_ls switch_param(s_my_ls param, char p) {
    switch (p) {
        case 'r':
            param.lsr = 1;
            break;
        case 'R':
            param.lsR = 1;
            break;
        case 'l':
            param.lsl = 1;
            break;
        case 't':
            param.lst = 1;
            break;
        case 'd':
            param.lsd = 1;
            break;
        default :
            param.valid = 0;
    }
    return (param);
}