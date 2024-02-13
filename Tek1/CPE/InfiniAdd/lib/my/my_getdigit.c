/*
** EPITECH PROJECT, 2020
** my_getdigit
** File description:
** my_getdigit
*/

int my_getdigit(char c)
{
    if (c >= '0' && c <= '9')
        c -= 48;
    return (c);
}