/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04am-tanguy.bellicha
** File description:
** concat
*/

#include "./concat.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = (char *) malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    strcat(strcpy(*res, str1), str2);
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}
