/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int size = 0;
    int i = 0;

    while (dest[size])
        size++;
    while (src[i]) {
        dest[size] = src[i];
        size++;
        i++;
    }
    dest[size] = 0;
    return (dest);
}

char *my_strcat_char(char *dest, char src)
{
    int size = 0;

    while (dest[size])
        size++;
    dest[size] = src;
    size++;
    dest[size] = 0;
    return (dest);
}
