/*
** EPITECH PROJECT, 2020
** get_color
** File description:
** desc
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int result = 0;

    result = (red << 24) | (green << 8) | blue;
    return (result);
}
