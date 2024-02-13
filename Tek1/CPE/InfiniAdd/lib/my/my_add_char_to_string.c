/*
** EPITECH PROJECT, 2020
** my_add_char_to_num
** File description:
** my_add_char_to_string
*/

char *my_add_char_to_string(char *dest, char c)
{
    int length;

    length = 0;
    while (dest[length] != 0)
        length++;
    length--;
    dest[length] = c;
    dest[length + 1] = 0;
    return (dest);
}